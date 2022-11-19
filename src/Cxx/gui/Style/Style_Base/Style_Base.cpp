#include "Style_Base.h"

#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

import Cxx::graphics;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Style_Base)

const Color Style_Base::NormalColor = Color::White;
const Color Style_Base::PreLightColor = Color::Red;
const Color Style_Base::InsensitiveColor = Color::DarkGray;
const Color Style_Base::ActiveColor = Color::Blue;
const Color Style_Base::FocusColor = Color::Green;

Style_Base& Style_Base::init() {
	setBackgroundColor(Color::LightGrey);
	setForegroundColor(Color::Black);
	return self;
}

void Style_Base::remove() {

}

Style_Base& Style_Base::init(Component *component) {
	init();
	Style::init(component);

	return self;
}

Style_Base& Style_Base::copy(const Style_Base &other) {
	return self;
}

Style_Base& Style_Base::move(Style_Base &&other) {
	return self;
}

void Style_Base::paintComponent(Graphics2D *g2d) {
	g2d->setColor(getBackgroundColor());
	g2d->fillRect(component->getOutRect());
	g2d->setColor(ActiveColor);
	g2d->drawRect(component->getOutRect());
}

void Style_Base::paintLabel(Graphics2D *g2d) {
}

void Style_Base::paintPushButton(Graphics2D *g2d) {
}

void Style_Base::paintCheckButton(Graphics2D *g2d) {
}

void Style_Base::paintRadioButton(Graphics2D *g2d) {
}

void Style_Base::paintGroupBox(Graphics2D *g2d) {
}

void Style_Base::paintPanel(Graphics2D *g2d) {
}

}
}
