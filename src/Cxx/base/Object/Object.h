#pragma once

#include "Cxx/config.h"

namespace Cxx {
namespace base {

class String;

class Object {
CXX_OBJECT_DEF(Object)

public:
	virtual Object& init();
	virtual void remove();

public:
	Object& copy(const Object &other);
	Object& move(Object &&other);

public:
	virtual String& toString();
};

}
}
