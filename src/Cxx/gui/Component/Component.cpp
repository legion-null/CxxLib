#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

import Cxx::graphics;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Component)

Style *Component::CurrentDefaultStyle = nullptr;

Component& Component::init() {
	this->style = new Style_Base(this);
	return self;
}

void Component::remove() {

}

Component& Component::init(i32 x, i32 y, i32 width, i32 height) {
	this->style = new Style_Base(this);

	outRect.init(x, y, width, height);
	return self;
}

Component& Component::copy(const Component &other) {
	return self;
}

Component& Component::move(Component &&other) {
	return self;
}

i32 Component::getX() const {
	return outRect.getX();
}

i32 Component::getY() const {
	return outRect.getY();
}

void Component::getPos(i32 &x, i32 &y) const {
	outRect.getPos(x, y);
}

void Component::setX(i32 x) {
	outRect.setX(x);
}

void Component::setY(i32 y) {
	outRect.setY(y);
}

void Component::setPos(i32 x, i32 y) {
	outRect.setPos(x, y);
}

i32 Component::getWidth() const {
	return outRect.getWidth();
}

i32 Component::getHeight() const {
	return outRect.getHeight();
}

void Component::getSize(i32 &width, i32 &height) const {
	outRect.getSize(width, height);
}

void Component::setWidth(i32 width) {
	outRect.setWidth(width);
}

void Component::setHeight(i32 height) {
	outRect.setHeight(height);
}

void Component::setSize(i32 width, i32 height) {
	outRect.setSize(width, height);
}

const Rect2D& Component::getOutRect() const {
	return outRect;
}

void Component::setOutRect(graphics::Rect2D &rect) {
	outRect.copy(rect);
}

Component* Component::getParent() const {
	return parent;
}

void Component::setParent(Component *parent) {
	this->parent = parent;
}

void Component::paint(graphics::Graphics2D *g2d) {
	if (this->style == nullptr)
		throw Exception();

	style->paint(g2d);
}

}
}
