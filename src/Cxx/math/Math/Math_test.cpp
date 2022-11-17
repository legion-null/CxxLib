#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;
import Cxx::math;

i32 math_Math_test_main() {

	Log::Print(Log::DebugLog, "%lf\n", Math::Sqrt(81));

	return 0;
}
