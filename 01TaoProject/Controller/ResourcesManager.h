#ifndef _RESOURCES_MANAGER_H
#define _RESOURCES_MANAGER_H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <Vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace bejeweled {
	using std::string;
	using std::vector;

	/************************************************************************/
	/* Lop su dung de load hay unload images va font
	No co the co nhieu instance - thay vi la 1 lop singleton
	*/
	/************************************************************************/
	class ResourcesManager
	{
	public:
		ResourcesManager(void);

		//Giai phong tat cac cac images trong lop nay
		virtual ~ResourcesManager(void);

		/************************************************************************/
		/* Load va toi uu mot versions cua images va luu no trong surfaces vector,
		no se duoc giai phong o ham huy. Ham hay chi duoc goi sau khi goi SetVideoMode*/
		/************************************************************************/
		SDL_Surface* loadImage(const string &path);

		/************************************************************************/
		/* Load 1 hinh anh chua qua xu ly. 
		Co the goi no truoc ham SetVideoMode.*/
		/************************************************************************/
		SDL_Surface* loadSimpleImage(const string &path);

		/************************************************************************/
		/* Load 1 font va luu no vao fonts vector, se duoc giai phong o ham huy.
		Font phai dat o trong pham vi local path.*/
		/************************************************************************/
		TTF_Font* loadFont(const string& path, int size);

		/************************************************************************/
		/* Load 1 file am thanh va luu no vao music files vector, se duoc giai phong o ham huy.
		File am thanh trong pham vi local path.
		/************************************************************************/
		Mix_Music* loadMusic(const string & path);

		/************************************************************************/
		/* Load 1 file effect va luu no vao effects files vector, se duoc giai phong o ham huy.
		Effect file phai thuoc pham vi local.*/
		/************************************************************************/
		Mix_Chunk* loadEffect(const string &path);

	private:
		/// Ngan chan sao chep va Assigment
		ResourcesManager(const ResourcesManager&);
		ResourcesManager& operator = (const ResourcesManager&);

		vector<SDL_Surface*> m_surfaces;
		vector<TTF_Font*> m_fonts;
		vector<Mix_Music*> m_musics;
		vector<Mix_Chunk*> m_effects;
	};

}

#endif