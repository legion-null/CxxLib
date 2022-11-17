#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace math {

class Random: extends base::Object {
CXX_OBJECT_DEF0

public:
	static f32 Random();
	static bool Random();
};

}
}
