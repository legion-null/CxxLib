#pragma once

#include "Cxx/gui/Component/Component.h"
#include "Cxx/templates/List/List.hpp"

namespace Cxx {
namespace gui {

class Container: extends Component {
CXX_OBJECT_DEF(Container)

protected:
	templates::List<Component*> componentList = templates::List<Component*>();

public:
	virtual Container& init() override;
	virtual void remove() override;

public:
	Container& copy(const Container &other);
	Container& move(Container &&other);


public:
	void add(Component *component);
	void remove(Component *component);
};

}
}
