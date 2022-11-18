#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Color/Color.h"

namespace Cxx {
namespace graphics {
class Graphics2D;
}
namespace gui {

class Component;

abstract_class UI: extends base::Object {
CXX_OBJECT_DEF(UI)

public:
	UI(Component *component) {
		init(component);
	}

protected:
	Component *component = nullptr;

public:
	graphics::Color backgroundColor;
	graphics::Color foregroundColor;

public:
	virtual UI& init() override;
	virtual void remove() override;

public:
	UI& init(Component *component);

public:
	UI& copy(const UI &other);
	UI& move(UI &&other);

public:
	Component* getComponent() const;

public:
	void setComponent(Component *component);

public:
	virtual void paint(graphics::Graphics2D *g2d) = 0;

};

}
}
