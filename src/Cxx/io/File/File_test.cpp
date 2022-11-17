#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

import Cxx::io;

i32 io_File_test_main() {
	File stdout(File::StandardOut);

	byte b[] = "Hello,World!";
	stdout.write(b, 12);

	return 0;
}
