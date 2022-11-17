#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Point2D)

Point2D& Point2D::init() {
	return self;
}

void Point2D::remove() {

}

Point2D& Point2D::init(i32 x, i32 y) {
	setPos(x, y);
	return self;
}

Point2D& Point2D::copy(const Point2D &other) {
	return self;
}

Point2D& Point2D::move(Point2D &&other) {
	return self;
}

i32 Point2D::getX() const {
	return x;
}

i32 Point2D::getY() const {
	return y;
}

void Point2D::getPos(i32 &x, i32 &y) const {
	x = this->x;
	y = this->y;
}

void Point2D::setX(i32 x) {
	this->x = x;
}

void Point2D::setY(i32 y) {
	this->y = y;
}

void Point2D::setPos(i32 x, i32 y) {
	this->x = x;
	this->y = y;
}

void Point2D::move(i32 dx, i32 dy) {
	this->x += dx;
	this->y += dy;
}

void Point2D::rotate(Point2D &o, f32 angle) {

}

void Point2D::rotate(f32 angle) {
	Point2D p(0, 0);
	rotate(p, angle);
}

}
}
