#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace math {
CXX_ABSTRACT_OBJECT_REALIZATION(Cxx::math::Math)

const f64 Math::E = 2.7182818284590452354;
const f64 Math::Log2E = 1.4426950408889634074;
const f64 Math::Log10E = 0.43429448190325182765;
const f64 Math::Ln2 = 0.69314718055994530942;
const f64 Math::Ln10 = 2.30258509299404568402;
const f64 Math::Pi = 3.14159265358979323846;
const f64 Math::Pi_2 = 1.57079632679489661923;
const f64 Math::Pi_4 = 0.78539816339744830962;
const f64 Math::M1_Pi = 0.31830988618379067154;
const f64 Math::M2_Pi = 0.63661977236758134308;
const f64 Math::M2_SqrtPi = 1.12837916709551257390;
const f64 Math::Sqrt2 = 1.41421356237309504880;
const f64 Math::Sqrt1_2 = 0.70710678118654752440;

#include "QuickTable.h"

i32 Math::Factorial(i32 a) {
	i32 ret = a;
	while (a > 1) {
		a--;
		ret *= a;
	}
	return ret;
}

i32 Math::A(i32 m, i32 n) {
	if (m == 0)
		return 1;

	return Factorial(n) / Factorial(n - m);
}

i32 Math::C(i32 m, i32 n) {
	if (m == 0)
		return 1;

	return Factorial(n) / (Factorial(m) * Factorial(n - m));
}

f64 Math::Sqrt(f64 x) {
	f64 val = x; //最终
	f64 last; //保存上一个计算的值
	do {
		last = val;
		val = (val + x / val) / 2;
	} while (Abs(val - last) > 0.0001);
	return val;
}

f64 Math::Sin(f64 d) {
	return Math::Sin64[(i32) (d * 100)];
}

f64 Math::Cos(f64 d) {
	return Math::Cos64[(i32) (d * 100)];
}

f64 Math::Tan(f64 d) {
	return Math::Tan64[(i32) (d * 100)];
}

}
}
