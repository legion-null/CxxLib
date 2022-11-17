#pragma once

#include <Cxx/graphics/Point2D/Point2D.h>

namespace Cxx {
namespace graphics {

class Point3D: extends Point2D {
CXX_OBJECT_DEF(Point3D)

protected:
	i32 z = 0;

public:
	Point3D(i32 x, i32 y, i32 z){
		init(x, y, z);
	}

public:
	virtual Point3D& init() override;
	virtual void remove() override;

public:
	Point3D& init(i32 x, i32 y, i32 z);

public:
	Point3D& copy(const Point3D &other);
	Point3D& move(Point3D &&other);

private:
	using Point2D::getPos;
	using Point2D::setPos;
	using Point2D::move;
	using Point2D::rotate;

public:
	i32 getZ() const;

	void getPos(i32 &x, i32 &y, i32 &z) const;

public:
	void setZ(i32 z);

	void setPos(i32 x, i32 y, i32 z);

public:
	void move(i32 dx, i32 dy, i32 dz);

public:

};

}
}
