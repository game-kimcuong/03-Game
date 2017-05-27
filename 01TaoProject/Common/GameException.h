#ifndef _GAME_EXCEPTION_
#define _GAME_EXCEPTION_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <stdexcept>
#include <string>

/************************************************************************/
/* Lop bat loi trong game. Cac loi lien quan thu vien SDL se hien thi dang
text va duoc tra ra.													*/
/************************************************************************/

namespace bejeweled {

	using std::runtime_error;
	using std::string;

	class GameException : public runtime_error
	{
	public:
		//Ham tao  voi dau vao rong
		GameException(void);
		
		//Ham tao tu 1 tham chieu string&
		GameException(const string&);

		//Ham tao voi con tro char*
		GameException(const char*);
		virtual ~GameException(void) throw();
	};
}


#endif
