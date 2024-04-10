

#ifndef LINKEDLISTHPP
#define LINKEDLISTHPP

#include <iostream>
#include "LinkedList.h"
using namespace std;


template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n) {
	ListNode<T> *aNewNode = new ListNode<T>(n);
	if (_head == NULL)
		_tail = aNewNode;
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
    assert(_size>0);
	if (_size > 0) {
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
		if (_size == 0)
			_tail = NULL;
	}
}

template <class T>
void List<T>::print(bool withoutSpace) {

	ListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		if (!withoutSpace)
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
	  
}



template <class T>
T List<T>::headItem()
{
    assert(_head);
    return _head->_item;
}


template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};

template <class T>
bool List<T>::exist(T n) {
    ListNode<T> current = _head;
	while (current != nullptr){
		if (current->_item == n) {return true;}
		current = current->_next;
	}
	return false;
}

template <class T>
void List<T>::insertTail(T n)
{
    ListNode<T> *new_element = new ListNode<T>(n);
    if (this->_tail != nullptr){
        this->_tail->_next = new_element;
    }
    this->_tail = new_element;
    if (this->_head == nullptr){
        this->_head = new_element;
    }
    this->_size++;
    return;
};

template <class T>
void List<T>::removeTail() {
    ListNode<T>* temp;
    ListNode<T>* curr;
    temp = this->_tail;
    curr = this->_head;
    while (curr->_next != this->_tail) {curr = curr->_next;}
    curr->_next = nullptr;
    this->_tail = curr;
    delete temp;
 }

#endif
