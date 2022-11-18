#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Point2D/Point2D.h"

namespace Cxx {
namespace graphics {

abstract_class AbstractShape2D: extends Cxx::base::Object {
CXX_ABSTRACT_OBJECT_DEF(AbstractShape2D)

protected:
	Point2D pos;
	Point2D *points = nullptr;



public:
	//virtual f32 getArea();
};

}
}
