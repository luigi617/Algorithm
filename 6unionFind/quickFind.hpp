#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef QUICKFINDHPP
#define QUICKFINDHPP

#define DEFAULTHEAPSIZE 1023



class QuickFind {
 protected:
  int* _componentId;
  int _size;

 public:
  QuickFind(int n) {
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

  ~QuickFind() { delete[] _componentId; };
};

void QuickFind::print() {
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

bool QuickFind::find(int q, int p) {
  return _componentId[q] == _componentId[p];
}

void QuickFind::union_(int q, int p) {
  for (int i=0; i<_size; i++){
    if (_componentId[i] == _componentId[q]){
      _componentId[i] = _componentId[p];
    }
  }

}

#endif