#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Point2D/Point2D.h"

namespace Cxx {
namespace graphics {

class Shape2D: extends Cxx::base::Object {
CXX_OBJECT_DEF(Shape2D)

public:
	Shape2D(i32 x, i32 y) {
		init(x, y);
	}

protected:
	Point2D pos;
	Point2D *points = nullptr;
	i32 numOfPoints = 0;

public:
	virtual Shape2D& init() override;
	virtual void remove() override;

public:
	Shape2D& init(i32 x, i32 y);

public:
	Shape2D& copy(const Shape2D &other);
	Shape2D& move(Shape2D &&other);

public:
	i32 getX() const;
	i32 getY() const;

	void getPos(i32 &x, i32 &y) const;

public:
	void setX(i32 x);
	void setY(i32 y);

	void setPos(i32 x, i32 y);

public:
	Point2D getPoint(i32 index) const;

public:
	virtual f32 getArea() = 0;

};

}
}
