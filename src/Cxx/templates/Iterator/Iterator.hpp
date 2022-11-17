#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace templates {

template<class E>
template_class Iterator: extends Cxx::base::Object {
CXX_TEMPLATE_OBJECT_DEF(Iterator)

public:
	virtual bool hasPast() = 0;
	virtual E past() = 0;

	virtual bool hasNext() = 0;
	virtual E next() = 0;

	virtual void remove() = 0;
};
CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::templates::Iterator)

}
}
