#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace portings {
CXX_OBJECT_REALIZATION(Cxx::portings::SDL2)

SDL2& SDL2::init() {
	return self;
}

void SDL2::remove() {

}

SDL2& SDL2::copy(const SDL2 &other) {
	return self;
}

SDL2& SDL2::move(SDL2 &&other) {
	return self;
}

}
}
