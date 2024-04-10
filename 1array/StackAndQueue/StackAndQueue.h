#pragma once
#include "../linkedList/LinkedList.h"

template <class T>
class Stack
{
private:
	List<T> _l;

public:

	void push(T item) {
		this->_l.insertHead(item);
		return;
	}
	T pop() {
		T head_element;
		head_element = this->_l.headItem();
		this->_l.removeHead();
		return head_element;
	}
	void print(bool withoutSpace = false) { _l.print(withoutSpace); };
	bool empty() { return _l.size() == 0; };
};

template <class T>
class Queue {
private:
	List<T> _l;

public:

	void enqueue(T item) {
		this->_l.insertTail(item);
		return;
	}

	T dequeue() {
		T head_element;
		head_element = this->_l.headItem();
		this->_l.removeHead();
		return head_element; 
	}
	void print(bool withoutSpace = false) { _l.print(withoutSpace); };
	bool empty() { return _l.size() == 0; };
};
