#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace gui {
CXX_OBJECT_REALIZATION(Cxx::gui::Label)Label& Label::init() {
	return self;
}

void Label::remove() {

}

Label& Label::copy(const Label &other) {
	return self;
}

Label& Label::move(Label &&other) {
	return self;
}

}
}
