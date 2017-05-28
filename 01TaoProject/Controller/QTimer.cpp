#include "QTimer.h"
#include <SDL.h>

namespace bejeweled {
	QTimer::QTimer(void) : 
	m_startedTicks(0),
	m_pausedTicks(0),
	m_paused(false),
	m_started(false)
	{

	}


	QTimer::~QTimer(void)
	{

	}

	void QTimer::start() {
		m_started = true;
		m_paused = false;
		m_startedTicks = SDL_GetTicks();
	}

	void QTimer::stop() {
		m_started = false;
		m_paused = false;
	}

	void QTimer::pause() {
		if (m_started && !m_paused) {
			m_paused = true;
			m_pausedTicks = SDL_GetTicks() - m_startedTicks;
		}
	}

	void QTimer::unpause() {
		if (m_paused) {
			m_paused = false;
			m_startedTicks = SDL_GetTicks() - m_pausedTicks;
			m_pausedTicks = 0;
		}
	}

	int QTimer::getTicks() const {
		if (m_started) {
			if (m_paused) {
				return m_pausedTicks;
			}

			return SDL_GetTicks() - m_startedTicks;
		}

		return 0;
	}

	bool QTimer::isStarted() const {
		return m_started;
	}

	bool QTimer::isPaused() const {
		return m_paused;
	}
}

