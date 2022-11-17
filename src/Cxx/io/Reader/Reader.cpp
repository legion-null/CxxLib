#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace io {
CXX_OBJECT_REALIZATION(Cxx::io::Reader)

Reader& Reader::init() {
	return self;
}

void Reader::remove() {

}

Reader& Reader::copy(const Reader &other) {
	return self;
}

Reader& Reader::move(Reader &&other) {
	return self;
}


c8 Reader::read() {
	return 0;
}

void Reader::read(c8 *buf) {
}

void Reader::read(c8 *buf, i32 len) {
}

}
}
