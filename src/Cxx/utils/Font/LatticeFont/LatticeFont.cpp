#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace utils {
CXX_OBJECT_REALIZATION(Cxx::utils::LatticeFont)

LatticeFont& LatticeFont::init() {
	return self;
}

void LatticeFont::remove() {

}

LatticeFont& LatticeFont::copy(const LatticeFont &other) {
	return self;
}

LatticeFont& LatticeFont::move(LatticeFont &&other) {
	return self;
}

}
}
