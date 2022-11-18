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

Style& Style::copy(const Style &other) {
	return self;
}

Style& Style::move(Style &&other) {
	return self;
}

}
}
