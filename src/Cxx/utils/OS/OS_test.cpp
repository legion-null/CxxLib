#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;
import Cxx::utils;

i32 utils_OS_test_main() {
	String name;

	while (true) {
		OS::WriteLine("输入你的名字并按下回车键：");
		name = OS::ReadLine();
		OS::WriteLine("你的名字是 " + name);
	}

	return 0;
}
