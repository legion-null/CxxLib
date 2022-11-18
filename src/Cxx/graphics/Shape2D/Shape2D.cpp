#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Shape2D)

Shape2D& Shape2D::init() {
	return self;
}

void Shape2D::remove() {

}

Shape2D& Shape2D::init(i32 x, i32 y) {
	setPos(x, y);
	return self;
}

Shape2D& Shape2D::copy(const Shape2D &other) {
	return self;
}

Shape2D& Shape2D::move(Shape2D &&other) {
	return self;
}

i32 Shape2D::getX() const {
	return this->pos.getX();
}

i32 Shape2D::getY() const {
	return this->pos.getY();
}

void Shape2D::getPos(i32 &x, i32 &y) const {
	this->pos.getPos(x, y);
}

void Shape2D::setX(i32 x) {
	this->pos.setX(x);
}

void Shape2D::setY(i32 y) {
	this->pos.setY(y);
}

void Shape2D::setPos(i32 x, i32 y) {
	this->pos.setPos(x, y);
}

Point2D Shape2D::getPoint(i32 index) const {
	if (index < 0 || index >= numOfPoints)
		throw Exception();

	return this->points[index];
}

}
}
