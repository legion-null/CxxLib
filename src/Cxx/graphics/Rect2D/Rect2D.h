#pragma once

#include "Cxx/graphics/AbstractShape2D/AbstractShape2D.h"

namespace Cxx {
namespace graphics {

class Rect2D: extends AbstractShape2D {
CXX_OBJECT_DEF(Rect2D)

protected:
	i32 width = 0;
	i32 height = 0;

public:
	Rect2D(i32 x, i32 y, i32 width, i32 height){
		init(x, y, width, height);
	}

public:
	virtual Rect2D& init() override;
	virtual void remove() override;

public:
	Rect2D& init(i32 x, i32 y, i32 width, i32 height);

public:
	Rect2D& copy(const Rect2D &other);
	Rect2D& move(Rect2D &&other);

};

}
}
