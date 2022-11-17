#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace math {

abstract_class Math: extends Cxx::base::Object {
CXX_ABSTRACT_OBJECT_DEF(Math)

public:
	static const f64 E;
	static const f64 Log2E;
	static const f64 Log10E;
	static const f64 Ln2;
	static const f64 Ln10;
	static const f64 Pi;
	static const f64 Pi_2;
	static const f64 Pi_4;
	static const f64 M1_Pi;
	static const f64 M2_Pi;
	static const f64 M2_SqrtPi;
	static const f64 Sqrt2;
	static const f64 Sqrt1_2;

	static const f64 Sin64[];
	static const f64 Cos64[];
	static const f64 Tan64[];

public:
	template<class E>
	static E Abs(E a) {
		return a > 0 ? a : -a;
	}

	template<class E>
	static E Max(E a, E b) {
		return a > b ? a : b;
	}

	template<class E>
	static E Min(E a, E b) {
		return a < b ? a : b;
	}

public:
	template<class E>
	static E Power(E x, i32 n) {
		E ret = 1;
		for (i32 i = 0; i < n; i++)
			ret *= x;
		return ret;
	}

public:
	static i32 Factorial(i32 a);
	static i32 A(i32 m, i32 n);
	static i32 C(i32 m, i32 n);

public:
	static f64 Sqrt(f64 x);

public:
	static f64 Sin(f64 d);
	static f64 Cos(f64 d);
	static f64 Tan(f64 d);

public:
	static f32 Random();

};



}
}
