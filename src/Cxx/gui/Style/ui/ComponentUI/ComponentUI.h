#pragma once

#include "Cxx/gui/UI/UI.h"

namespace Cxx {
namespace gui {

class Component;

abstract_class ComponentUI: extends UI {
CXX_OBJECT_DEF(ComponentUI)

public:
	virtual ComponentUI& init() override;
	virtual void remove() override;

public:
	ComponentUI& copy(const ComponentUI &other);
	ComponentUI& move(ComponentUI &&other);

};

}
}
