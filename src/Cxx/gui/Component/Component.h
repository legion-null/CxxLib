#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Rect2D/Rect2D.h"

namespace Cxx {
namespace graphics {
class Graphics2D;
}
namespace gui {

class Style;

class Component: extends Cxx::base::Object {
CXX_OBJECT_DEF(Component)

public:
	typedef enum State : i8 {
		Normal,		// 常规
		Prelight,	// 鼠标指针悬停
		Insensitive,// 不敏感
		Active,		// 当前活动
		Focus		// 获得输入设备焦点
	} State;

protected:
	static Style *CurrentDefaultStyle;

public:
	Component(i32 x, i32 y, i32 width, i32 height) {
		init(x, y, width, height);
	}

protected:
	graphics::Rect2D outRect;

	Component *parent = nullptr;

protected:
	i8 visual :1;

protected:
	Style *style = nullptr;

public:
	virtual Component& init() override;
	virtual void remove() override;

public:
	Component& init(i32 x, i32 y, i32 width, i32 height);

public:
	Component& copy(const Component &other);
	Component& move(Component &&other);

public:
	i32 getX() const;
	i32 getY() const;

	void getPos(i32 &x, i32 &y) const;

public:
	void setX(i32 x);
	void setY(i32 y);

	void setPos(i32 x, i32 y);

public:
	i32 getWidth() const;
	i32 getHeight() const;

	void getSize(i32 &width, i32 &height) const;

public:
	void setWidth(i32 width);
	void setHeight(i32 height);

	void setSize(i32 width, i32 height);

public:
	const graphics::Rect2D& getOutRect() const;

public:
	void setOutRect(graphics::Rect2D &rect);

public:
	Component* getParent() const;
	void setParent(Component *parent);

public:
	void paint(graphics::Graphics2D *g2d);

};

}
}
