#ifndef _QTIMER_H_
#define _QTIMER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace bejeweled {
	
	/************************************************************************/
	/* Mo ta bo dem thoi gian cua game.
	*/
	/************************************************************************/
	class QTimer
	{
	public:
		QTimer(void);

		/// Cac ham xu ly timer
		void start();
		void stop();
		void pause();
		void unpause();

		/// Lay time cua timer
		int getTicks() const;

		//Check status cua timer
		bool isStarted() const;
		bool isPaused() const;

		virtual ~QTimer(void);

	private:

		/// thoi gian dong ho khi timer bat dau start
		int m_startedTicks;

		/// So ticks khi pause timer
		int m_pausedTicks;

		/// Trang thai timer
		bool m_paused;
		bool m_started;
	};
}


#endif
