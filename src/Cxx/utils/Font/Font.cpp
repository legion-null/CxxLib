#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace utils {
CXX_OBJECT_REALIZATION(Cxx::utils::Font)

Font& Font::init() {
	return self;
}

void Font::remove() {

}

Font& Font::copy(const Font &other) {
	return self;
}

Font& Font::move(Font &&other) {
	return self;
}

}
}
