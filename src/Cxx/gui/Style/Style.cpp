#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Style)

Style& Style::init() {
	return self;
}

void Style::remove() {

}

Style& Style::init(Component *component) {
	setComponent(component);

	return self;
}

Style& Style::copy(const Style &other) {
	return self;
}

Style& Style::move(Style &&other) {
	return self;
}

Component* Style::getComponent() const {
	return this->component;
}

void Style::setComponent(Component *component) {
	this->component = component;
}

const graphics::Color& Style::getBackgroundColor() const {
	return backgroundColor;
}

const graphics::Color& Style::getForegroundColor() const {
	return foregroundColor;
}

void Style::setBackgroundColor(const graphics::Color &backgroundColor) {
	this->backgroundColor = backgroundColor;
}

void Style::setForegroundColor(const graphics::Color &foregroundColor) {
	this->foregroundColor = foregroundColor;
}

void Style::paint(graphics::Graphics2D *g2d) {
	if (this->component == nullptr)
		throw Exception();

	// 绘制组件基本内容
	this->paintComponent(g2d);

	if (1) {

	}
}

}
}
