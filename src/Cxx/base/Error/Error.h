#pragma once

#include "Cxx/base/Exception/Exception.h"

namespace Cxx {
namespace base {

class Error: extends Exception {
CXX_OBJECT_DEF(Error)

public:
	Error(String &info) {
		init(info);
	}

public:
	virtual Error& init() override;
	virtual void remove() override;

public:
	Error& init(String &info);

public:
	Error& copy(const Error &other);
	Error& move(Error &&other);
};

}
}
