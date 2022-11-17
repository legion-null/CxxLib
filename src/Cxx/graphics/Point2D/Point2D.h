#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace graphics {

class Point2D: extends base::Object {
CXX_OBJECT_DEF(Point2D)

protected:
	i32 x = 0;
	i32 y = 0;

public:
	Point2D(i32 x, i32 y){
		init(x, y);
	}

public:
	virtual Point2D& init() override;
	virtual void remove() override;

public:
	Point2D& init(i32 x, i32 y);

public:
	Point2D& copy(const Point2D &other);
	Point2D& move(Point2D &&other);

public:
	i32 getX() const;
	i32 getY() const;

	void getPos(i32 &x, i32 &y) const;

public:
	void setX(i32 x);
	void setY(i32 y);

	void setPos(i32 x, i32 y);

public:
	void move(i32 dx, i32 dy);

public:
	void rotate(Point2D &o, f32 angle);
	void rotate(f32 angle);
};

}
}
