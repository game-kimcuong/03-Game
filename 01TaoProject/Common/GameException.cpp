#include "GameException.h"
#include <SDL.h>

namespace bejeweled {
	GameException::GameException(void) : runtime_error(SDL_GetError())
	{

	}

	GameException::GameException(const string& msg) : runtime_error(msg) {

	}

	GameException::GameException(const char* msg) : runtime_error(msg) {

	}

	GameException::~GameException(void)  throw()
	{

	}
}

