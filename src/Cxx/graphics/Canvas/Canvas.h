#pragma once

#include "Cxx/graphics/FrameBuffer/FrameBuffer.h"

#include "Cxx/graphics/Graphics/Graphics.h"
#include "Cxx/graphics/Color/Color.h"

namespace Cxx {
namespace graphics {

class Canvas: extends FrameBuffer {
CXX_OBJECT_DEF(Canvas)

protected:
	Graphics::Rot rot = Graphics::Rot_0;

public:
	Canvas(i32 width, i32 height, i32 bpp, Graphics::Rot rot) {
		init(width, height, bpp, rot);
	}

public:
	virtual Canvas& init() override;
	virtual void remove() override;

public:
	Canvas& init(i32 width, i32 height, i32 bpp, Graphics::Rot rot);

public:
	Canvas& copy(const Canvas &other);
	Canvas& move(Canvas &&other);

public:

private:
	using FrameBuffer::readPixel;
	using FrameBuffer::writePixel;

	using FrameBuffer::writeLineH;
	using FrameBuffer::writeLineV;
	using FrameBuffer::writeRect;

public:
	Graphics::Rot getRot() const;
	void setRot(Graphics::Rot rot);

public:
	void mapPoint(i32 &x, i32 &y);
	void iMapPoint(i32 &x, i32 &y);

public:
	Color getPoint(i32 x, i32 y);
	void drawPoint(i32 x, i32 y, const Color &color);

public:
	void drawLineH(i32 x0, i32 y0, i32 width, const Color &color);
	void drawLineV(i32 x0, i32 y0, i32 height, const Color &color);
	void fillRect(i32 x0, i32 y0, i32 width, i32 height, const Color &color);

public:
	void clear(const Color &color);
	void clear();

};

}
}
