#pragma once

#include "Cxx/gui/Container/Container.h"

namespace Cxx {
namespace gui {

class Label: extends Container {
CXX_OBJECT_DEF(Label)

public:
	virtual Label& init() override;
	virtual void remove() override;

public:
	Label& copy(const Label &other);
	Label& move(Label &&other);

};

}
}
