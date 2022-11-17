#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace io {

class Reader: extends base::Object {
CXX_OBJECT_DEF(Reader)

public:
	virtual Reader& init() override;
	virtual void remove() override;

public:
	Reader& copy(const Reader &other);
	Reader& move(Reader &&other);


public:
	virtual c8 read();
	virtual void read(c8 *buf);
	virtual void read(c8 *buf, i32 len);
};

}
}
