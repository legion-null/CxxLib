#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace types {
CXX_OBJECT_REALIZATION(Cxx::types::Num)

Num& Num::init() {
	return self;
}

void Num::remove() {

}

Num& Num::copy(const Num &other) {
	return self;
}

Num& Num::move(Num &&other) {
	return self;
}

}
}
