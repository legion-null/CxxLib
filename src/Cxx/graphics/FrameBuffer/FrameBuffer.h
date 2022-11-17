#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace graphics {

class FrameBuffer: extends Cxx::base::Object {
CXX_OBJECT_DEF(FrameBuffer)

public:
	static void CopyRect(const FrameBuffer &src, FrameBuffer &dest, i32 x0, i32 y0, i32 width, i32 height);

	static void Copy(const void *src, void *dest, i32 size);
	static void Copy(const FrameBuffer &src, FrameBuffer &dest);

protected:
	i32 width = 0;
	i32 height = 0;

	i32 bpp = 0;

protected:
	i32 pSize = 0;
	i32 lineSize = 0;
	i32 fbSize = 0;

protected:
	u8 *fb = nullptr;
	u8 **fbX = nullptr;

public:
	FrameBuffer(i32 width, i32 height, i32 bpp) {
		init(width, height, bpp);
	}

public:
	virtual FrameBuffer& init() override;
	virtual void remove() override;

public:
	FrameBuffer& init(i32 width, i32 height, i32 bpp);

public:
	FrameBuffer& copy(const FrameBuffer &other);
	FrameBuffer& move(FrameBuffer &&other);



public:
	i32 getWidth() const;
	i32 getHeight() const;
	i32 getBpp() const;

private:
	bool isLegalPixel(i32 x0, i32 y0) const;

public:
	i32 readPixel(i32 x0, i32 y0) const;
	void writePixel(i32 x0, i32 y0, i32 colorData);

public:
	void writeLineH(i32 x0, i32 y0, i32 width, i32 colorData);
	void writeLineV(i32 x0, i32 y0, i32 height, i32 colorData);
	void writeRect(i32 x0, i32 y0, i32 width, i32 height, i32 colorData);

public:
	void clear(i32 colorData);

};

}
}
