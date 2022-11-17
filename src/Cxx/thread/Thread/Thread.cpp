#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace thread {
CXX_OBJECT_REALIZATION(Cxx::thread::Thread)

Thread& Thread::init() {
	return self;
}

void Thread::remove() {

}

Thread& Thread::copy(const Thread &other) {
	return self;
}

Thread& Thread::move(Thread &&other) {
	return self;
}

}
}
