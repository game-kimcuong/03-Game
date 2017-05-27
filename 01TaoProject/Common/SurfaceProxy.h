#ifndef _SURFACE_PROXY_H_
#define _SURFACE_PROXY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <utility>
#include <string>
#include "SDL.h"
#include "Point.h"

namespace bejeweled {
	using std::string;

	/*
	Xu ly loading surfaces
	Su dung de toi uu hien thi 1 hinh anh tren display format
	dong thoi su dung de ve surfaces

	*/
	class SurfaceProxy
	{
	public:
		/************************************************************************/
		/* Proxy load SDL_surface va tra ve mot version toi uu
		Chung ta khong muon SDL thay doi format hinh anh luon luon - do vay chung ta 
		se chu dong convert chung.
		cho 1 vi du, hinh anh la 24bit depth, va kich thuoc man hinh la 32bit.
		Chung ta co the goi no sau khi chung ta set movde video voi ham SDL_SetVideoMode.

		*/
		/************************************************************************/
		static SDL_Surface* loadOptimizedImage(const string& path);
		 /*
		 Proxies goi cho IMG_load. Khong su dung optimize cho loaded image.
		 No co the an toan de goi truoc khi dung SDL_SetVideoMode.
		 Vi du: khi load 1 icon
		 */
		static SDL_Surface* loadRegularImage(const string& path);

		/*
		Su dung de ve cac surface theo cac thong so nhat dinh
		*/
		static void draw(int x, int y, SDL_Surface* src, SDL_Surface* dst, SDL_Rect* clip = NULL);

		/*
		Tra ve kich thuoc mot hinh anh o duong dan xac dinh
		*/
		static Point getImageDimensions(const string& path);

	private:
		SurfaceProxy(void);
		SurfaceProxy(const SurfaceProxy&);
		SurfaceProxy& operator=(const SurfaceProxy&);
	public:
		virtual ~SurfaceProxy(void);
	};
}


#endif
