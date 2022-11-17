#pragma once

#include "Cxx/config.h"

namespace Cxx {

template<class E>
E Abs(E a) {
	return a >= 0 ? a : -a;
}

template<class E>
E Diff(E &a, E &b) {
	return Abs(a - b);
}

template<class E>
E Min(E a, E b) {
	return a <= b ? a : b;
}

template<class E>
E Max(E a, E b) {
	return a >= b ? a : b;
}

}
