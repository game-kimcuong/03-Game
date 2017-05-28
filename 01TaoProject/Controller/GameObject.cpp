#include "GameObject.h"

namespace bejeweled {
	GameObject::GameObject(void) : 
	m_dstSUrfaces(NULL), 
	m_originX(0),
	m_originY(0)
	{
	}

	GameObject::GameObject(int x, int y, SDL_Surface* target /* = NULL */):
	m_dstSUrfaces(target),
	m_originX(x),
	m_originY(y)
	{


	}

	void GameObject::setOrigin(int x, int y) {
		m_originX = x;
		m_originY = y;
	}

	void GameObject::setTargetSurface(SDL_Surface* target) {
		m_dstSUrfaces = target;
	}

	GameObject::~GameObject(void)
	{
	}
}

