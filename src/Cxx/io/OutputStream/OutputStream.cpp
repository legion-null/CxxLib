#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace io {
CXX_OBJECT_REALIZATION(Cxx::io::OutputStream)

OutputStream& OutputStream::init() {
	return self;
}

void OutputStream::remove() {

}

OutputStream& OutputStream::init(File &file) {
	return self;
}

OutputStream& OutputStream::copy(const OutputStream &other) {
	return self;
}

OutputStream& OutputStream::move(OutputStream &&other) {
	return self;
}

void OutputStream::write(byte b) {
	file.writeByte(b);
}

void OutputStream::write(byte *b, i32 len) {
	for (i32 i = 0; i < len; i++)
		write(b[i]);
}


}
}
