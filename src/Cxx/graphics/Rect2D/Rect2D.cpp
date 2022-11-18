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
	Shape2D::init();
	return self;
}

Rect2D& Rect2D::copy(const Rect2D &other) {
	return self;
}

Rect2D& Rect2D::move(Rect2D &&other) {
	return self;
}

i32 Rect2D::getWidth() const {
	return width;
}

i32 Rect2D::getHeight() const {
	return height;
}

void Rect2D::getSize(i32 &width, i32 &height) const {
	width = this->width;
	height = this->height;
}

void Rect2D::setWidth(i32 width) {
	this->width = width;
}

void Rect2D::setHeight(i32 height) {
	this->height = height;
}

void Rect2D::setSize(i32 width, i32 height) {
	this->width = width;
	this->height = height;
}

f32 Rect2D::getArea() {
	return width * height;
}

}
}
