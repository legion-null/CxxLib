#pragma once

#include "Cxx/io/AbstractStream/AbstractStream.h"

namespace Cxx {
namespace io {

class OutputStream: extends AbstractStream {
CXX_OBJECT_DEF(OutputStream)

public:
	OutputStream(File &file) {
		init(file);
	}

public:
	virtual OutputStream& init() override;
	virtual void remove() override;

public:
	OutputStream& init(File &file);

public:
	OutputStream& copy(const OutputStream &other);
	OutputStream& move(OutputStream &&other);

public:
	virtual void write(byte b);
	virtual void write(byte *b, i32 len);
};

}
}
