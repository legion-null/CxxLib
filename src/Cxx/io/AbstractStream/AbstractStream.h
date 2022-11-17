#pragma once

#include "Cxx/base/Object/Object.h"
#include "Cxx/io/File/File.h"

namespace Cxx {
namespace io {

abstract_class AbstractStream: extends base::Object {
CXX_ABSTRACT_OBJECT_DEF(AbstractStream)

protected:
	File file;

protected:
	i8 stateClose :1;

public:
	AbstractStream();
	virtual ~AbstractStream();

public:
	AbstractStream(File &file);

public:
	virtual void close();
	virtual void flush();
};

}
}
