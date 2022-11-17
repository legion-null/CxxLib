#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace io {

class Writer: extends base::Object {
CXX_OBJECT_DEF(Writer)

public:
	virtual Writer& init() override;
	virtual void remove() override;

public:
	Writer& copy(const Writer &other);
	Writer& move(Writer &&other);

public:
	virtual void write(const c8 character);
	virtual void write(const c8 *buf);
	virtual void write(const c8 *buf, i32 len);
};

}
}
