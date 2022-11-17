#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::base::Exception)

Exception& Exception::init() {
	return self;
}

void Exception::remove() {
}

Exception& Exception::init(String &info) {
	return self;
}

Exception& Exception::init(Type type) {
	return self;
}

Exception& Exception::copy(const Exception &other) {
	return self;
}

Exception& Exception::move(Exception &&other) {
	return self;
}

}
}
