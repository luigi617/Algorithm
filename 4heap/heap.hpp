#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

#define DEFAULTHEAPSIZE 1023


template <class T>
class Heap {
 protected:
  T* _heap;
  int _size;

 public:
  Heap() { _heap = new T[DEFAULTHEAPSIZE]; _size = 0;}

  int size() const {
    return _size;
  }

  bool empty() const {
    return _size == 0;
  }
  void swap(int pos1, int pos2);
  void bubbleup(int current_pos);
  void bubbledown(int current_pos);

  void insert(const T&);
  T extractMax();
  T peekMax() const;
  void printHeapArray() const;
  void printTree() const;
  void changeKey(const T& from, const T& to);
  void deleteItem(const T&);

  ~Heap() { delete[] _heap; };
};

template <class T>
void Heap<T>::swap(int pos1, int pos2) {
  T temp = _heap[pos1];
  _heap[pos1] = _heap[pos2];
  _heap[pos2] = temp;
}
template <class T>
void Heap<T>::bubbleup(int current_pos) {
  int current_index = current_pos;
  int parent_index = floor((current_index - 1)/2);
  if (parent_index >= 0 & _heap[current_index] > _heap[parent_index]){
    swap(current_index, parent_index);
    bubbleup(parent_index);
  }
}
template <class T>
void Heap<T>::bubbledown(int current_pos) {
  int current_index = current_pos;
  int left_index = 2 * current_index + 1;
  int right_index = 2 * current_index + 2;
  int largest_child_index;
  if (max(left_index, right_index) < _size){
    largest_child_index = _heap[right_index] > _heap[left_index] ? right_index : left_index;
  } else if (min(left_index, right_index) >= _size) {
    return;
  } else {
    largest_child_index = left_index < _size ? left_index : right_index;
  }
  if (_heap[largest_child_index] > _heap[current_index]){
    swap(current_index, largest_child_index);
    bubbledown(largest_child_index);
  }
}

template <class T>
void Heap<T>::insert(const T& item) {
  _heap[_size] = item;
  bubbleup(_size);
  _size++;
}

template <class T>
T Heap<T>::extractMax() {
  T max_item = peekMax(); // if emtpy, peekMax throws error
  swap(0, _size - 1);
  _size--;
  bubbledown(0);
  return max_item;
}

template <class T>
T Heap<T>::peekMax() const {
  if (empty()){throw out_of_range("empty heap");}
  return _heap[0];
};

template <class T>
void Heap<T>::printHeapArray() const {
  for (int i = 0; i < size(); i++) {
    cout << _heap[i] << " ";
  }
  cout << endl;
}

template <class T>
void Heap<T>::changeKey(const T& from, const T& to) {
  int item_index = 0;
  for (item_index = 0; item_index < size(); item_index++){
    if (_heap[item_index] == from){
      break;
    }
  }
  if (item_index == size()){return;}
  _heap[item_index] = to;
  if (from < to){
    bubbleup(item_index);
  } else {
    bubbledown(item_index);
  }
}

template <class T>
void Heap<T>::deleteItem(const T& x) {
  int item_index = 0;
  for (item_index = 0; item_index < size(); item_index++){
    if (_heap[item_index] == x){
      break;
    }
  }
  if (item_index == size()){return;}
  swap(item_index, _size - 1);
  _size--;
  if (_heap[item_index] > _heap[item_index]){
    bubbleup(item_index);
  } else {
    bubbledown(item_index);
  }
}

template <class T>
void Heap<T>::printTree() const {
  int parity = 0;
  if (size() == 0) return;
  int space = pow(2, 1 + (int)log2f(size())), i;
  int nLevel = (int)log2f(size()) + 1;
  int index = 0, endIndex;
  int tempIndex;

  for (int l = 0; l < nLevel; l++) {
    index = 1;
    parity = 0;
    for (i = 0; i < l; i++) index *= 2;
    endIndex = index * 2 - 1;
    index--;
    tempIndex = index;
    while (index < size() && index < endIndex) {
      for (i = 0; i < space - 1; i++) cout << " ";
      if (index == 0)
        cout << "|";
      else if (parity)
        cout << "\\";
      else
        cout << "/";
      parity = !parity;
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }
    cout << endl;
    index = tempIndex;
    while (index < size() && index < endIndex) {
      for (i = 0; i < (space - 1 - ((int)log10(_heap[index]))); i++)
        cout << " ";
      cout << _heap[index];
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }

    cout << endl;
    space /= 2;
  }
}

#endif
