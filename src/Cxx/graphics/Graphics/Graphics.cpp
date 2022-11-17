#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_ABSTRACT_OBJECT_REALIZATION(Cxx::graphics::Graphics)

void Graphics::MapPoint(i32 &x, i32 &y, i32 &width, i32 &height, Rot rot) {
	i32 x0 = x;
	i32 y0 = y;

	switch (rot) {
	case Rot_0:
		break;
	case Rot_90:
		x = y0;
		y = height - 1 - x0;
		break;
	case Rot_180:
		x = width - 1 - x0;
		y = height - 1 - y0;
		break;
	case Rot_270:
		x = width - 1 - y0;
		y = x0;
		break;
	}
}

void Graphics::IMapPoint(i32 &x, i32 &y, i32 &width, i32 &height, Rot rot) {
	i32 x0 = x;
	i32 y0 = y;

	switch (rot) {
	case Rot_0:
		break;
	case Rot_90:
		x = height - 1 - y0;
		y = x0;
		break;
	case Rot_180:
		x = width - 1 - x0;
		y = height - 1 - y0;
		break;
	case Rot_270:
		x = y0;
		y = width - 1 - x0;
		break;
	}
}
}
}
