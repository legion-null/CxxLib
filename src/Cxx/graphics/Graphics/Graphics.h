#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace graphics {

abstract_class Graphics: extends Cxx::base::Object {
CXX_ABSTRACT_OBJECT_DEF(Graphics)

public:
	typedef enum Rot : i8 {
		Rot_0, Rot_90, Rot_180, Rot_270,
	} Rot;

public:
	static void MapPoint(i32 &x, i32 &y, i32 &width, i32 &height, Rot rot);
	static void IMapPoint(i32 &x, i32 &y, i32 &width, i32 &height, Rot rot);

};

}
}
