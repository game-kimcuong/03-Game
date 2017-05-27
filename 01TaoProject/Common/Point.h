#ifndef _POINT_H_
#define _POINT_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <utility>

namespace bejeweled {
	// Lop Point dai dien cho toa do 2D dang (x, y) la kieu nguyen
	typedef std::pair<int, int> Point;
}
#endif 