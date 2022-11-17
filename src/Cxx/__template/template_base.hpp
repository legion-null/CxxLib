#pragma once

#include "Cxx/config.h"

namespace Cxx {

template<class E>
void Swap(E &a, E &b) {
	E temp = a;
	a = b;
	b = temp;
}

template<class E>
void Copy(E *src, E *dest, i32 num) {
	for (i32 i = 0; i < num; i++) {
		dest[i] = src[i];
	}
}

template<class E>
void Move(E *src, E *dest, i32 num) {
	Copy(src, dest, num);
	delete[] src;
}


}
