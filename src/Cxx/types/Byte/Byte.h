#pragma once

#include "Cxx/types/Num/Num.h"

namespace Cxx {
namespace types {

class Byte: extends Num {
CXX_OBJECT_DEF(Byte)

protected:

public:
	Byte(const byte value) {
		init(value);
	}

public:
	Byte& operator=(const byte value){
		return init(value);
	}

public:
	virtual Byte& init() override;
	virtual void remove() override;

public:
	Byte& init(const byte value);

public:
	Byte& copy(const Byte &other);
	Byte& move(Byte &&other);

};

}
}
