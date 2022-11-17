#pragma once

#include "Cxx/base/Interface/Interface.h"

namespace Cxx {
namespace thread {

interface_class Runnable: implements base::Interface {
CXX_INTERFACE_DEF(Runnable)

public:
	virtual void run() = 0;

};

}
}
