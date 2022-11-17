#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace types {
CXX_OBJECT_REALIZATION(Cxx::types::Byte)

Byte& Byte::init() {
	return self;
}

void Byte::remove() {

}

Byte& Byte::init(const byte value) {

	return self;
}

Byte& Byte::copy(const Byte &other) {
	return self;
}

Byte& Byte::move(Byte &&other) {
	return self;
}



}
}
