#include "Cxx/Cxx.h"

#include <stdio.h>

import Cxx;
import Cxx::base;
import Cxx::dev;
import Cxx::io;

namespace Cxx {
namespace utils {
CXX_ABSTRACT_OBJECT_REALIZATION(Cxx::utils::OS)

void OS::WriteLine(const String &string) {
	File::StandardOutput.write((byte*) string.toCharArray(), string.getLength());
	File::StandardOutput.writeByte('\n');

	File::StandardOutput.flush();
}

String OS::ReadLine() {
	c8 *buf = new c8[1024];
	for (i32 i = 0;; i++) {
		File::StandardInput.read((byte*) (buf + i), 1);
		if (buf[i] == 10)
			break;
	}

	File::StandardInput.flush();

	String ret(buf);
	delete[] buf;

	return ret;
}

}
}
