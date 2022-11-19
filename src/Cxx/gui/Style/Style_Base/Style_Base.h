#pragma once

#include "Cxx/gui/Style/Style.h"

namespace Cxx {
namespace gui {

class Style_Base: extends Style {
CXX_OBJECT_DEF(Style_Base)

protected:
	static const graphics::Color NormalColor;
	static const graphics::Color PreLightColor;
	static const graphics::Color InsensitiveColor;
	static const graphics::Color ActiveColor;
	static const graphics::Color FocusColor;

public:
	Style_Base(Component *component){
		init(component);
	}

public:
	virtual Style_Base& init() override;
	virtual void remove() override;

public:
	Style_Base& init(Component *component);

public:
	Style_Base& copy(const Style_Base &other);
	Style_Base& move(Style_Base &&other);

protected:
	virtual void paintComponent(graphics::Graphics2D *g2d) override;

	virtual void paintLabel(graphics::Graphics2D *g2d) override;

	virtual void paintPushButton(graphics::Graphics2D *g2d) override;
	virtual void paintCheckButton(graphics::Graphics2D *g2d) override;
	virtual void paintRadioButton(graphics::Graphics2D *g2d) override;

	virtual void paintGroupBox(graphics::Graphics2D *g2d) override;

	virtual void paintPanel(graphics::Graphics2D *g2d) override;
};

}
}
