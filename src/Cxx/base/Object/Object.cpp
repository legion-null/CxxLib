#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::base::Object)

Object& Object::init() {
	return self;
}

void Object::remove() {
}

Object& Object::copy(const Object &other) {
	return self;
}

Object& Object::move(Object &&other) {
	return self;
}

String& Object::toString() {
	String *string = new String("Hello,World");
	return *string;

}

}
}
