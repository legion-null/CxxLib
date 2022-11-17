#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Canvas)

Canvas& Canvas::init() {
	return self;
}

void Canvas::remove() {
}

Canvas& Canvas::init(i32 width, i32 height, i32 bpp, Graphics::Rot rot) {
	FrameBuffer::init(width, height, bpp);

	Log::Print(Log::DebugLog, "Canvas::Canvas(%d, %d, %d, %d)\n", width, height, bpp, rot);
	this->rot = rot;

	return self;
}

Canvas& Canvas::copy(const Canvas &other) {
	return self;
}

Canvas& Canvas::move(Canvas &&other) {
	return self;
}

Graphics::Rot Canvas::getRot() const {
	return rot;
}

void Canvas::setRot(Graphics::Rot rot) {
	this->rot = rot;
}

void Canvas::mapPoint(i32 &x, i32 &y) {
	return Graphics::MapPoint(x, y, width, height, rot);
}

void Canvas::iMapPoint(i32 &x, i32 &y) {
	return Graphics::IMapPoint(x, y, width, height, rot);
}

Color Canvas::getPoint(i32 x, i32 y) {
	mapPoint(x, y);
	return FrameBuffer::readPixel(x, y);
}

void Canvas::drawPoint(i32 x, i32 y, const Color &color) {
	mapPoint(x, y);
	return FrameBuffer::writePixel(x, y, color.getValue());
}

void Canvas::drawLineH(i32 x0, i32 y0, i32 width, const Color &color) {
	mapPoint(x0, y0);
	FrameBuffer::writeLineH(x0, y0, width, color.getValue());
}

void Canvas::drawLineV(i32 x0, i32 y0, i32 height, const Color &color) {
	mapPoint(x0, y0);
	FrameBuffer::writeLineV(x0, y0, height, color.getValue());
}

void Canvas::fillRect(i32 x0, i32 y0, i32 width, i32 height, const Color &color) {
	mapPoint(x0, y0);
	FrameBuffer::writeRect(x0, y0, width, height, color.getValue());
}

void Canvas::clear(const Color &color) {
	FrameBuffer::clear(color.getValue());
}

void Canvas::clear() {
	FrameBuffer::clear(0);
}

}
}
