#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace io {
CXX_ABSTRACT_OBJECT_REALIZATION(Cxx::io::AbstractStream)

AbstractStream::AbstractStream() {
}

AbstractStream::~AbstractStream() {
}

AbstractStream::AbstractStream(File &file) {
	this->file = file;
}

void AbstractStream::close() {
	file.close();
}

void AbstractStream::flush() {
	file.flush();
}

}
}
