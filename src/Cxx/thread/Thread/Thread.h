#pragma once

#include "Cxx/base/Object/Object.h"
#include "Cxx/thread/Runnable/Runnable.h"

namespace Cxx {
namespace thread {

class Thread: extends Cxx::base::Object, implements Runnable {
CXX_OBJECT_DEF(Thread)

public:
	virtual Thread& init() override;
	virtual void remove() override;

public:
	Thread& copy(const Thread &other);
	Thread& move(Thread &&other);

};

}
}
