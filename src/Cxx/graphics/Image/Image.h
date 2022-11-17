#pragma once

#include "Cxx/graphics/FrameBuffer/FrameBuffer.h"

namespace Cxx {
namespace graphics {

class Image: extends FrameBuffer {
CXX_OBJECT_DEF(Image)

public:
	Image(FrameBuffer *fb) {
		init(fb);
	}

	Image(FrameBuffer *fb, i32 x0, i32 y0, i32 width, i32 height) {
		init(fb, x0, y0, width, height);
	}

	Image(const base::String &path) {
		init(path);
	}

public:
	virtual Image& init() override;
	virtual void remove() override;

public:
	Image& init(FrameBuffer *fb);
	Image& init(FrameBuffer *fb, i32 x0, i32 y0, i32 width, i32 height);

	Image& init(const base::String &path);

public:
	Image& copy(const Image &other);
	Image& move(Image &&other);

private:
	using FrameBuffer::getBpp;

	using FrameBuffer::readPixel;
	using FrameBuffer::writePixel;

	using FrameBuffer::writeLineH;
	using FrameBuffer::writeLineV;
	using FrameBuffer::writeRect;

public:
	Color getPoint(i32 x0, i32 y0);

};

}
}

#include "BMP/Image_BMP.h"
