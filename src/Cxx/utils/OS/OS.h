#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/io/File/File.h"

namespace Cxx {
namespace utils {

abstract_class OS: extends Cxx::base::Object {
CXX_ABSTRACT_OBJECT_DEF(OS)

public:
	static void WriteLine(const base::String &string);
	static base::String ReadLine();
};

}
}
