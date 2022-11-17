#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::base::Error)

Error& Error::init() {
	return self;
}

void Error::remove() {
}

Error& Error::init(String &info) {
	return self;
}

Error& Error::copy(const Error &other) {
	return self;
}

Error& Error::move(Error &&other) {
	return self;
}

}
}
