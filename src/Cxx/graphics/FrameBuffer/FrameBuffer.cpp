#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::FrameBuffer)

void FrameBuffer::CopyRect(const FrameBuffer &src, FrameBuffer &dest, i32 x0, i32 y0, i32 width, i32 height) {
}

void FrameBuffer::Copy(const void *src, void *dest, i32 size) {
	u8 *p1 = (u8*) src;
	u8 *p2 = (u8*) dest;

	for (int i = 0; i < size; i++) {
		*p2 = *p1;
		p1++;
		p2++;
	}
}

void FrameBuffer::Copy(const FrameBuffer &src, FrameBuffer &dest) {
	if (src.width != dest.width || src.height != dest.height || src.bpp != dest.bpp)
		return;

	Copy(src.fb, dest.fb, src.fbSize);
}

FrameBuffer& FrameBuffer::init() {
	return self;
}

void FrameBuffer::remove() {
	if (fb != nullptr)
		delete[] fb;

	if (fbX != nullptr)
		delete[] fbX;
}

FrameBuffer& FrameBuffer::init(i32 width, i32 height, i32 bpp) {
	Log::Print(Log::DebugLog, "FrameBuffer::FrameBuffer(%d, %d, %d)\n", width, height, bpp);

	this->width = width;
	this->height = height;
	this->bpp = bpp;

	this->pSize = this->bpp / 8;
	this->lineSize = this->pSize * this->width;
	this->fbSize = this->lineSize * this->height;

	// fb初始化
	this->fb = new u8[this->fbSize];

	// fbX初始化
	this->fbX = new u8*[this->height];
	for (i32 i = 0; i < this->height; i++)
		this->fbX[i] = &(this->fb[this->lineSize * i]);

	return self;
}

FrameBuffer& FrameBuffer::copy(const FrameBuffer &other) {
	return self;
}

FrameBuffer& FrameBuffer::move(FrameBuffer &&other) {
	return self;
}

i32 FrameBuffer::getWidth() const {
	return width;
}

i32 FrameBuffer::getHeight() const {
	return height;
}

i32 FrameBuffer::getBpp() const {
	return bpp;
}

bool FrameBuffer::isLegalPixel(i32 x0, i32 y0) const {
	if (x0 < 0 || x0 >= width || y0 < 0 || y0 >= height)
		return false;
	return true;
}

i32 FrameBuffer::readPixel(i32 x0, i32 y0) const {
	switch (pSize) {
	case 1:
		return *(((u8*) ((fbX[y0]))) + x0);
	case 2:
		return *(((u16*) ((fbX[y0]))) + x0);
	case 3: {
		u8 *p = (((u8*) (fbX[y0])) + 3 * x0);
		return (*p << 16) | (*(p + 1) << 8) | *(p + 2);
	}
	case 4:
		return *(((u32*) ((fbX[y0]))) + x0);
	}
	return 0;
}

void FrameBuffer::writePixel(i32 x0, i32 y0, i32 colorData) {
	switch (pSize) {
	case 1:
		*(((u8*) ((fbX[y0]))) + x0) = (u8) (colorData);
		break;
	case 2:
		*(((u16*) ((fbX[y0]))) + x0) = (u16) (colorData);
		break;
	case 3: {
		u8 *p = (((u8*) (fbX[y0])) + 3 * x0);
		*(p + 0) = 0xff & (colorData >> 16);
		*(p + 1) = 0xff & (colorData >> 8);
		*(p + 2) = 0xff & (colorData >> 0);
		break;
	}
	case 4:
		*(((u32*) ((fbX[y0]))) + x0) = (u32) (colorData);
		break;
	}
}

void FrameBuffer::writeLineH(i32 x0, i32 y0, i32 width, i32 colorData) {
	i32 x1 = x0 + width - 1;
	for (i32 x = x0; x <= x1; x++)
		writePixel(x, y0, colorData);
}

void FrameBuffer::writeLineV(i32 x0, i32 y0, i32 height, i32 colorData) {
	i32 y1 = y0 + height - 1;
	for (i32 y = y0; y <= y1; y++)
		writePixel(x0, y, colorData);
}

void FrameBuffer::writeRect(i32 x0, i32 y0, i32 width, i32 height, i32 colorData) {
	i32 y1 = y0 + height - 1;
	for (i32 y = y0; y <= y1; y++)
		writeLineH(x0, y, width, colorData);
}

void FrameBuffer::clear(i32 colorData) {
	writeRect(0, 0, width, height, colorData);
}

}
}
