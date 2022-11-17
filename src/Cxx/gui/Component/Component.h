#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace graphics{
class Graphics2D;
}
namespace gui {

class Component: extends Cxx::base::Object {
CXX_OBJECT_DEF(Component)

protected:
	i32 x = 0;
	i32 y = 0;
	i32 width = 0;
	i32 height = 0;

	Component *parent = nullptr;

	i8 visual :1;

public:
	virtual Component& init() override;
	virtual void remove() override;

public:
	Component& copy(const Component &other);
	Component& move(Component &&other);


public:
	i32 getX() const;
	i32 getY() const;

	void getXY(i32 &x, i32 &y) const;

	void setX(i32 x);
	void setY(i32 y);

	void setXY(i32 x, i32 y);

	i32 getWidth() const;
	i32 getHeight() const;

	void getSize(i32 &width, i32 &height) const;

	void setWidth(i32 width);
	void setHeight(i32 height);

	void setSize(i32 width, i32 height);

public:
	Component* getParent() const;
	void setParent(Component *parent);

public:
	void paint(graphics::Graphics2D *g2d);


};

}
}
