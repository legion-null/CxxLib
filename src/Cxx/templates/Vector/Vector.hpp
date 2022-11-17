#pragma once

#include "Cxx/templates/Container/Container.hpp"

namespace Cxx {
namespace templates {

template<class E>
template_class Vector: extends Container<E> {
CXX_TEMPLATE_OBJECT_DEF(Vector)

protected:
	E *vector = nullptr;
	i32 volume = 0; // 容量

public:
	Vector<E>() {
		reserve(100);
	}

	virtual ~Vector() {

	}

protected:
	void reserve(i32 volume) { // 设置容量
		if (volume < this->volume)
			throw base::Exception();

		// 加互斥锁
		E *temp = new E[volume];

		for (i32 i = 0; i < getSize(); i++) {
			temp[i] = vector[i];
		}

		this->volume = volume;
		Swap(vector, temp);
		// 释放互斥锁

		delete temp;
	}

	void expand(i32 addSize) {
		while (getSize() + addSize >= getVolume())
			reserve(2 * volume);
	}

public:
	i32 getVolume() const {
		return volume;
	}

	bool isFull() const {
		if (getSize() == getVolume())
			return true;
		else
			return false;
	}

public:
	virtual E get(i32 index) const override {
		if (!isIndexLegal(index))
			throw Cxx::base::Exception();

		return vector[index];
	}

public:
	virtual void add(E &e) override {
		// 加锁
		expand(1);
		vector[size++] = e;
		// 解锁
	}

	virtual void remove(i32 index) override {
		// 加锁
		if (!isIndexLegal(index))
			throw Cxx::base::Exception();

		this->size--;
		delete vector[index];

		for (i32 i = index; i < getSize(); i++) {
			vector[i] = vector[i + 1];
		}

		// 解锁
	}

	virtual void set(i32 index, E &e) override {
		// 加锁
		if (!isIndexLegal(index))
			throw Cxx::base::Exception();
		vector[index] = e;
		// 解锁
	}

	virtual i32 indexOf(E &e) override {
		for (i32 i = 0; i < getSize(); i++) {
			if (vector[i] == e)
				return i;
		}
		return -1;
	}

};

CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::templates::Vector)

}
}
