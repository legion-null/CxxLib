#pragma once

#include "Cxx/io/AbstractStream/AbstractStream.h"

namespace Cxx {
namespace io {

class File;

class InputStream: extends AbstractStream {
CXX_OBJECT_DEF(InputStream)

public:
	InputStream(File &file);

public:
	virtual InputStream& init() override;
	virtual void remove() override;

public:
	InputStream& init(File &file);

public:
	InputStream& copy(const InputStream &other);
	InputStream& move(InputStream &&other);

public:
	virtual byte read();
	virtual void read(byte *b, i32 len);
};

}
}
