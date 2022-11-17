#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Container)

Container& Container::init() {
	return self;
}

void Container::remove() {

}

Container& Container::copy(const Container &other) {
	return self;
}

Container& Container::move(Container &&other) {
	return self;
}

void Container::add(Component *component) {
	this->componentList.add(component);
}

void Container::remove(Component *component) {
	this->componentList.removeE(component);
}

}
}
