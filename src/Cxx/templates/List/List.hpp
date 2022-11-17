#pragma once

#include "Cxx/templates/Container/Container.hpp"

namespace Cxx {
namespace templates {

template<class E>
template_class List: extends Cxx::templates::Container<E> {
CXX_TEMPLATE_OBJECT_DEF(List)

protected:
	template<class E1>
	class ListNode {
	public:
		ListNode<E1> *past;
		ListNode<E1> *next;
		E1 value;

	public:
		ListNode<E1>(E1 &e) {
			this->past = this;
			this->next = this;

			this->value = e;
		}

		virtual ~ListNode() {

		}
	};

protected:
	ListNode<E> *head = nullptr;

public:
	List<E>() {

	}

	virtual ~List() {

	}

public:
	virtual E get(i32 index) const override {
		if (index == 0) {
			return head->value;
		} else if (index > 0) {
			ListNode<E> *p = head;
			for (i32 i = 0; i < index; i++)
				p = p->next;
			return p->value;
		} else {
			ListNode<E> *p = head;
			for (i32 i = 0; i > index; i--)
				p = p->past;
			return p->value;
		}
	}

public:
	virtual void add(E &e) override { // 在链表尾部添加
		if (this->isEmpty()) { // 头节点
			if (head != nullptr) {
				delete head;
				this->size = 0;
			}
			this->head = new ListNode<E>(e);
		} else { // 其它节点
			ListNode<E> *newNode = new ListNode<E>(e);

			newNode->next = head;
			newNode->past = head->past;
			head->past->next = newNode;
			head->past = newNode;
		}

		// 修改链表节点计数
		this->size++;
	}

	virtual void remove(i32 index) override { // 删除指定节点

	}

	virtual void set(i32 index, E &e) override {

	}

	virtual i32 indexOf(E &e) override {
		return 0;
	}

public:
	virtual Iterator<E>* iterator() override {
		return new ListIterator<E>(this);
	}

protected:
	template<class E1>
	template_class ListIterator: extends Cxx::templates::Iterator<E1> {
	private:
		List<E1> *list = nullptr;

	public:
		ListIterator<E1>() {

		}

		virtual ~ListIterator() {

		}

	public:
		ListIterator<E1>(List<E1> *list) {
			this->list = list;
		}

	public:
		virtual bool hasPast() override {
			return true;
		}

		virtual E1 past() override {
			return list->head->value;
		}

		virtual bool hasNext() override {
			return true;
		}

		virtual E1 next() override {
			return list->head->value;
		}

		virtual void remove() override {

		}
	};
};
CXX_TEMPLATE_OBJECT_REALIZATION(Cxx::templates::List)

}
}
