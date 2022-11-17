#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Rect2D)

Rect2D& Rect2D::init() {
	return self;
}

void Rect2D::remove() {

}

Rect2D& Rect2D::init(i32 x, i32 y, i32 width, i32 height) {
	return self;
}

Rect2D& Rect2D::copy(const Rect2D &other) {
	return self;
}

Rect2D& Rect2D::move(Rect2D &&other) {
	return self;
}

}
}
