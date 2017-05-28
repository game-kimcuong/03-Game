#include "ResourcesManager.h"
#include "../Common/SurfaceProxy.h"
#include "../Common/GameException.h"

namespace bejeweled {
	ResourcesManager::ResourcesManager(void)
	{
	}


	ResourcesManager::~ResourcesManager(void)
	{
		for (int i = 0; i < m_surfaces.size(); ++i) {
			SDL_FreeSurface(m_surfaces.at(i));
		}

		for (int i = 0; i < m_fonts.size(); ++i) {
			TTF_CloseFont(m_fonts.at(i));
		}

		for (int i = 0; i < m_musics.size(); ++i) {
			Mix_FreeMusic(m_musics.at(i));
		}

		for (int i = 0; i < m_effects.size(); ++i) {
			Mix_FreeChunk(m_effects.at(i));
		}

		m_surfaces.clear();
		m_fonts.clear();
		m_musics.clear();
		m_effects.clear();
	}

	SDL_Surface* ResourcesManager::loadImage(const string &path) {
		SDL_Surface* img = SurfaceProxy::loadOptimizedImage(path);

		m_surfaces.push_back(img);

		return img;
	}

	SDL_Surface* ResourcesManager::loadSimpleImage(const string &path) {
		SDL_Surface* img = SurfaceProxy::loadRegularImage(path);

		m_surfaces.push_back(img);

		return img;
	}

	TTF_Font* ResourcesManager::loadFont(const string& path, int size) {
		TTF_Font* font = TTF_OpenFont(path.c_str(), size);

		if (!font) {
			throw GameException();
		}

		m_fonts.push_back(font);

		return font;
	}

	Mix_Music* ResourcesManager::loadMusic(const string & path) {
		Mix_Music* music = Mix_LoadMUS(path.c_str());

		if (!music) {
			throw GameException();
		}

		m_musics.push_back(music);
		
		return music;
	}

	Mix_Chunk* ResourcesManager::loadEffect(const string &path) {
		Mix_Chunk* effect = Mix_LoadWAV(path.c_str());

		if (!effect) {
			throw GameException();
		}

		m_effects.push_back(effect);

		return effect;
	}

	ResourcesManager::ResourcesManager(const ResourcesManager& other) {
		this->operator=(other);
	}

	ResourcesManager& ResourcesManager::operator = (const ResourcesManager& other) {
		if (this != &other) {
			m_surfaces = other.m_surfaces;
			m_fonts = other.m_fonts;
			m_musics = other.m_musics;
			m_effects = other.m_effects;
		}

		return *this;
	}

}


