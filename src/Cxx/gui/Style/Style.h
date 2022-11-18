#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace gui {

abstract_class Style: extends base::Object {
CXX_OBJECT_DEF(Style)

public:
	static const Style& DefaultStyle;

protected:
	Component *component = nullptr;

public:
	virtual Style& init() override;
	virtual void remove() override;

public:
	Style& copy(const Style &other);
	Style& move(Style &&other);

public:
	virtual void paint(graphics::Graphics2D *g2d) = 0;

};

}
}
