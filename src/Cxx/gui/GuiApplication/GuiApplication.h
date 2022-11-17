#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace gui {

class GuiApplication: extends Cxx::base::Object {
CXX_OBJECT_DEF(GuiApplication)

public:
	virtual GuiApplication& init() override;
	virtual void remove() override;

public:
	GuiApplication& copy(const GuiApplication &other);
	GuiApplication& move(GuiApplication &&other);


};

}
}
