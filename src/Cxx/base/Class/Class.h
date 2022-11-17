#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace base {

class Class: extends Object {
CXX_OBJECT_DEF(Class)

public:
	virtual Class& init() override;
	virtual void remove() override;

public:
	Class& copy(const Class &other);
	Class& move(Class &&other);
};

}
}
