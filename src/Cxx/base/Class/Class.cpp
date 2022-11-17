#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::base::Class)

Class& Class::init() {
	return self;
}

void Class::remove() {
}

Class& Class::copy(const Class &other) {
	return self;
}

Class& Class::move(Class &&other) {
	return self;
}

}
}
