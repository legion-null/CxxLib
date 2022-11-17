#pragma once

#include "Cxx/base/Interface/Interface.h"
#include "Cxx/templates/Iterator/Iterator.hpp"

namespace Cxx {
namespace templates {

template<class E>
template_class Iterable: implements Cxx::base::Interface {
CXX_TEMPLATE_OBJECT_DEF(Iterable)

public:
	virtual Iterator<E>* iterator() = 0;
};

CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::templates::Iterable)

}
}
