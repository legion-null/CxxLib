#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Point3D)

Point3D& Point3D::init() {
	return self;
}

void Point3D::remove() {

}

Point3D& Point3D::init(i32 x, i32 y, i32 z) {
	setPos(x, y, z);
	return self;
}

Point3D& Point3D::copy(const Point3D &other) {
	return self;
}

Point3D& Point3D::move(Point3D &&other) {
	return self;
}

i32 Point3D::getZ() const {
	return z;
}

void Point3D::getPos(i32 &x, i32 &y, i32 &z) const {
	x = this->x;
	y = this->y;
	z = this->z;
}

void Point3D::setZ(i32 z) {
	this->z = z;
}

void Point3D::setPos(i32 x, i32 y, i32 z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point3D::move(i32 dx, i32 dy, i32 dz) {
	this->x += dx;
	this->y += dy;
	this->z += dz;
}

}
}
