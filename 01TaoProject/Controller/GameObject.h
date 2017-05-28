#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <SDL.h>
#include <utility>
#include "../Common/Point.h"

namespace bejeweled {

	/*
	Giao dien cho Game de co the update, draw, handle cac Events
	Cac doi tuong ve len man hinh se ke thua tu lop nay
	*/
	class GameObject
	{
	public:
		/*
		Ham tao, set surface = NULL va position (0, 0)
		*/
		GameObject(void);

		/*
		Ham tao, set surface va position tuy chinh
		*/
		GameObject(int x, int y, SDL_Surface* target = NULL);

		/// Ham huy, giai phong cac doi tuong da cap phat
		virtual ~GameObject(void);

		/*
		set vi tri cho object origin voi vi tri xac dinh
		*/
		void setOrigin(int x, int y);

		/// set cho doi tuong game 1 Serface, se duoc ghi de sau khi set
		void setTargetSurface(SDL_Surface* target);

	 /*
	  Vong lap game. Cac lop ke thua 3 ham nay se phai overwrite lai
	  */
	public:
		virtual void handleEvent(SDL_Event* event) = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

		//Ham xac dinh 1 diem thuoc Object khong
		virtual bool isPointInObject(int x, int y) const = 0;
	
	protected:
		SDL_Surface* m_dstSUrfaces;
		int m_originX, m_originY;

	};
}



#endif
