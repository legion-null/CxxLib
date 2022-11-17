#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace io {

Writer& Writer::init() {
	return self;
}

void Writer::remove() {

}

Writer& Writer::copy(const Writer &other) {
	return self;
}

Writer& Writer::move(Writer &&other) {
	return self;
}


void Writer::write(const c8 character) {

}

void Writer::write(const c8 *buf) {
}

void Writer::write(const c8 *buf, i32 len) {
}

}
}
