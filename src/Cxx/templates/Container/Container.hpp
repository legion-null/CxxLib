#pragma once

#include "Cxx/base/Object/Object.h"
#include "Cxx/templates/Iterable/Iterable.hpp"

#include "Cxx/base/Exception/Exception.h"

namespace Cxx {
namespace templates {

template<class E>
template_class Container: extends Cxx::base::Object, implements Cxx::templates::Iterable<E> {
CXX_TEMPLATE_OBJECT_DEF(Container)

protected:
	i32 size = 0;

public:
	bool isEmpty() const {
		return getSize() == 0 ? true : false;
	}

	i32 getSize() const {
		return size;
	}

public:
	virtual bool isIndexLegal(i32 index) const {
		if (index < 0 || index >= getSize())
			return false;
		return true;
	}

public:
	virtual E get(i32 index) const = 0;

public:
	virtual void add(E &e) = 0;
	virtual void remove(i32 index) = 0;
	virtual void set(i32 index, E &e) = 0;
	virtual i32 indexOf(E &e) = 0;

public:
	void removeE(E &e){
		i32 i = indexOf(e);

		if(!isIndexLegal(i))
			throw Cxx::base::Exception();

		remove(i);
	}
};
CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::templates::Container)

}
}
