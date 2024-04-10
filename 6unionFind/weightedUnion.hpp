#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef WEIGHTEDUNIONHPP
#define WEIGHTEDUNIONHPP




class WeightedUnion {
 protected:
  int* _componentId;
  int* _componentSize;
  int _size;

 public:
  WeightedUnion(int n) {
    _componentId = new int[n];
    _componentSize = new int[n];
    for (int i=0; i<n; i++){
      _componentId[i] = i;
      _componentSize[i] = 1;
    }
    _size = n;
  }

  int size() const {
    return _size;
  }

  bool find(int q, int p);
  void union_(int q, int p);
  void print();

  ~WeightedUnion() { delete[] _componentId; };
};

void WeightedUnion::print() {
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

bool WeightedUnion::find(int q, int p) {
  while (_componentId[q] != q) {q = _componentId[q];}
  while (_componentId[p] != p) {p = _componentId[p];}
  return (q == p);
}

void WeightedUnion::union_(int q, int p) {
  while (_componentId[q] != q) {q = _componentId[q];}
  while (_componentId[p] != p) {p = _componentId[p];}
  if (_componentSize[q] > _componentSize[p]){
    _componentId[p] = q;
    _componentSize[q] = _componentSize[q] + _componentSize[p];
  } else {
    _componentId[q] = p;
    _componentSize[p] = _componentSize[q] + _componentSize[p];
  }

}

#endif