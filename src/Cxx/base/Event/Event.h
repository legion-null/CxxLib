#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace base {

class Event: extends Object {
CXX_OBJECT_DEF(Event)

public:
	virtual Event& init() override;
	virtual void remove() override;

public:
	Event& copy(const Event &other);
	Event& move(Event &&other);
};

}
}
