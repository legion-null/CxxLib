#include "ComponentUI.h"

#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::ComponentUI)

ComponentUI& ComponentUI::init() {
	return self;
}

void ComponentUI::remove() {

}

ComponentUI& ComponentUI::copy(const ComponentUI &other) {
	return self;
}

ComponentUI& ComponentUI::move(ComponentUI &&other) {
	return self;
}
}
}
