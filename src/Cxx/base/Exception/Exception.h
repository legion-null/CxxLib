#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace base {

class Exception: extends Object {
CXX_OBJECT_DEF(Exception)

public:
	typedef enum Type : i8 {
		ArraySubscriptOutOfBounds,
	} Type;

public:
	Exception(String &info){
		init(info);
	}

	Exception(Type type){
		init(type);
	}

public:
	virtual Exception& init() override;
	virtual void remove() override;

public:
	Exception& init(String &info);
	Exception& init(Type type);

public:
	Exception& copy(const Exception &other);
	Exception& move(Exception &&other);


};

}
}
