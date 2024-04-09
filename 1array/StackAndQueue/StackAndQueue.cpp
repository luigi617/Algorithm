#include "StackAndQueue.h"

template <class T>
T Stack<T>::pop() {
    T head_element;
    head_element = this->_l.headItem();
    this->_l.removeHead();
    return head_element; 

}

template <class T>
void Queue<T>::enqueue(T item) {
    this->_l.insertTail(item);
    return;
}
template <class T>
T Queue<T>::dequeue() {
    T head_element;
    head_element = this->_l.headItem();
    this->_l.removeHead();
    return head_element; 
}