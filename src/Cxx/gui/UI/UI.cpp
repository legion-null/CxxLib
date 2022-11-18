#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::UI)

UI& UI::init() {
	return self;
}

void UI::remove() {

}

UI& UI::init(Component *component) {
	setComponent(component);
	return self;
}

UI& UI::copy(const UI &other) {
	return self;
}

UI& UI::move(UI &&other) {
	return self;
}

Component* UI::getComponent() const {
	return component;
}

void UI::setComponent(Component *component) {
	this->component = component;
}

}
}
