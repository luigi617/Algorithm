#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef QUICKUNIONHPP
#define QUICKUNIONHPP

#define DEFAULTHEAPSIZE 1023



class QuickUnion {
 protected:
  int* _componentId;
  int _size;

 public:
  QuickUnion(int n) {
    _componentId = new int[DEFAULTHEAPSIZE];
    for (int i=0; i<n; i++){
      _componentId[i] = i;
    }
    _size = n;
  }

  int size() const {
    return _size;
  }

  bool find(int q, int p);
  void union_(int q, int p);
  void print();

  ~QuickUnion() { delete[] _componentId; };
};

void QuickUnion::print() {
  int i;
  for (i=0; i<_size; i++){
    cout << i << '-';
  }
  cout << endl;
  for (i=0; i<_size; i++){
    cout << _componentId[i] << '-';
  }
  cout << endl;
}

bool QuickUnion::find(int q, int p) {
  while (_componentId[q] != q) {q = _componentId[q];}
  while (_componentId[p] != p) {p = _componentId[p];}
  return (q == p);
}

void QuickUnion::union_(int q, int p) {
  while (_componentId[q] != q) {q = _componentId[q];}
  while (_componentId[p] != p) {p = _componentId[p];}
  _componentId[q] = p;
}

#endif