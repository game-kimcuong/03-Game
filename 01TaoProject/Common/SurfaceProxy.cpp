#include "SurfaceProxy.h"
#include "SDL_image.h"
#include "GameException.h"
#include "Point.h"


namespace bejeweled {
	SDL_Surface* SurfaceProxy::loadOptimizedImage(const string& path) {
		SDL_Surface* loadedImage = IMG_Load(path.c_str());
		
		if (!loadedImage) {
			throw GameException();
		}

		SDL_Surface* optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

		if (!optimizedImage) {
			throw GameException();
		} else {
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
		}

		SDL_FreeSurface(loadedImage);

		return optimizedImage;
		
	}

	//Load anh khong co optimized
	SDL_Surface* SurfaceProxy::loadRegularImage(const string& path) {
		SDL_Surface* loadedImage = IMG_Load(path.c_str());

		if (!loadedImage) {
			throw GameException();
		}

		return loadedImage;
	}

	void SurfaceProxy::draw(int x, int y, SDL_Surface* src, SDL_Surface* dst, SDL_Rect* clip /* = NULL */) {
		if (!src || dst) {
			throw GameException("Khong the ve hinh tu 1 NULL Surface!");
		}

		SDL_Rect offset;

		offset.x = x;
		offset.y = y;

		if (SDL_BlitSurface(src, clip, dst, &offset)) {
			throw GameException();
		}
	}

	Point SurfaceProxy::getImageDimensions(const string& path) {
		SDL_Surface* loadedImage = IMG_Load(path.c_str());

		if (!loadedImage) {
			throw GameException();
		}

		int w = loadedImage->w;
		int h = loadedImage->h;

		SDL_FreeSurface(loadedImage);

		return std::make_pair(w, h);
	}


	SurfaceProxy::SurfaceProxy(void)
	{

	}

	SurfaceProxy::SurfaceProxy(const SurfaceProxy& surfaceProxy) {
		
	}

	SurfaceProxy& SurfaceProxy::operator=(const SurfaceProxy& surfaceProxy) {
		return *this;
	}

	SurfaceProxy::~SurfaceProxy(void)
	{

	}
}

