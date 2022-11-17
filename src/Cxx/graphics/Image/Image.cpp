#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Image)

Image& Image::init() {
	return self;
}

void Image::remove() {
}

Image& Image::init(FrameBuffer *fb) {
	return self;
}

Image& Image::init(FrameBuffer *fb, i32 x0, i32 y0, i32 width, i32 height) {
	return self;
}

Image& Image::init(const String &path) {
	return self;
}

Image& Image::copy(const Image &other) {
	return self;
}

Image& Image::move(Image &&other) {
	return self;
}

Color Image::getPoint(i32 x0, i32 y0) {
	return FrameBuffer::readPixel(x0, y0);
}

}
}
