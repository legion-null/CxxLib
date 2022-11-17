#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::base::Event)

Event& Event::init() {
	return self;
}

void Event::remove() {
}

Event& Event::copy(const Event &other) {
	return self;
}

Event& Event::move(Event &&other) {
	return self;
}

}
}
