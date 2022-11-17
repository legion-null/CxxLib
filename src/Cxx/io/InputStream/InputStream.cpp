#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace io {
CXX_OBJECT_REALIZATION(Cxx::io::InputStream)

InputStream& InputStream::init() {
	return self;
}

void InputStream::remove() {
}

InputStream& InputStream::init(File &file) {
	return self;
}

InputStream& InputStream::copy(const InputStream &other) {
	return self;
}

InputStream& InputStream::move(InputStream &&other) {
	return self;
}

byte InputStream::read() {
	return file.readByte();
}

void InputStream::read(byte *b, i32 len) {
	for (i32 i = 0; i < len; i++)
		b[i] = read();
}

}
}
