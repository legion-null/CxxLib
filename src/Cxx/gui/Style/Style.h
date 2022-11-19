#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Color/Color.h"

namespace Cxx {
namespace graphics {
class Graphics2D;
}
namespace gui {
class Component;

abstract_class Style: extends base::Object {
CXX_OBJECT_DEF(Style)

public:
	Style(Component *component) {
		init(component);
	}

protected:
	Component *component = nullptr;

protected:
	graphics::Color backgroundColor;	// 背景色
	graphics::Color foregroundColor;	// 前景色

public:
	virtual Style& init() override;
	virtual void remove() override;

public:
	Style& init(Component *component);

public:
	Style& copy(const Style &other);
	Style& move(Style &&other);

public:
	Component* getComponent() const;
	void setComponent(Component *component);

public:
	const graphics::Color& getBackgroundColor() const;
	const graphics::Color& getForegroundColor() const;

public:
	void setBackgroundColor(const graphics::Color &backgroundColor);
	void setForegroundColor(const graphics::Color &foregroundColor);

public:
	void paint(graphics::Graphics2D *g2d);

protected:
	virtual void paintComponent(graphics::Graphics2D *g2d) = 0;

protected:
	virtual void paintLabel(graphics::Graphics2D *g2d) = 0;

	virtual void paintPushButton(graphics::Graphics2D *g2d) = 0;
	virtual void paintCheckButton(graphics::Graphics2D *g2d) = 0;
	virtual void paintRadioButton(graphics::Graphics2D *g2d) = 0;

	virtual void paintPanel(graphics::Graphics2D *g2d) = 0;

	virtual void paintGroupBox(graphics::Graphics2D *g2d) = 0;
};

}
}

#include "Style_Base/Style_Base.h"
