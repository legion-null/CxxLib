#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Component)

Component& Component::init() {
	return self;
}

void Component::remove() {

}

Component& Component::copy(const Component &other) {
	return self;
}

Component& Component::move(Component &&other) {
	return self;
}

i32 Component::getX() const {
	return x;
}

i32 Component::getY() const {
	return y;
}

void Component::getXY(i32 &x, i32 &y) const {
	x = this->x;
	y = this->y;
}

void Component::setX(i32 x) {
	this->x = x;
}

void Component::setY(i32 y) {
	this->y = y;
}

void Component::setXY(i32 x, i32 y) {
	this->x = x;
	this->y = y;
}

i32 Component::getWidth() const {
	return width;
}

i32 Component::getHeight() const {
	return height;
}

void Component::getSize(i32 &width, i32 &height) const {
	width = this->width;
	height = this->height;
}

void Component::setWidth(i32 width) {
	this->width = width;
}

void Component::setHeight(i32 height) {
	this->height = height;
}

void Component::setSize(i32 width, i32 height) {
	this->width = width;
	this->height = height;
}

Component* Component::getParent() const {
	return parent;
}

void Component::setParent(Component *parent) {
	this->parent = parent;
}

}
}
