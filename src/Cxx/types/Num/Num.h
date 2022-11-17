#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace types {

class Num: extends Cxx::base::Object {
CXX_OBJECT_DEF(Num)

public:
	virtual Num& init() override;
	virtual void remove() override;

public:
	Num& copy(const Num &other);
	Num& move(Num &&other);

};

}
}
