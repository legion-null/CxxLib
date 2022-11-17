#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::GuiApplication)

GuiApplication& GuiApplication::init() {
	return self;
}

void GuiApplication::remove() {

}

GuiApplication& GuiApplication::copy(const GuiApplication &other) {
	return self;
}

GuiApplication& GuiApplication::move(GuiApplication &&other) {
	return self;
}

}
}
