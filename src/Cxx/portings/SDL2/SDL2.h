#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace portings {

class SDL2: extends Cxx::base::Object {
CXX_OBJECT_DEF(SDL2)

public:
	virtual SDL2& init() override;
	virtual void remove() override;

public:
	SDL2& copy(const SDL2 &other);
	SDL2& move(SDL2 &&other);

};

}
}
