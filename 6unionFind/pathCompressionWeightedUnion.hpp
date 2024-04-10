#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef PATHCOMPRESSIONWEIGHTEDUNIONHPP
#define PATHCOMPRESSIONWEIGHTEDUNIONHPP




class PathCompressionWeightedUnion {
 protected:
  int* _componentId;
  int* _componentSize;
  int _size;

 public:
  PathCompressionWeightedUnion(int n) {
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

  int findRoot(int p);
  bool find(int q, int p);
  void union_(int q, int p);
  void print();

  ~PathCompressionWeightedUnion() { delete[] _componentId; };
};

void PathCompressionWeightedUnion::print() {
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

int PathCompressionWeightedUnion::findRoot(int p) {
  // // grandparent pointer
  // int root = p;
  // while (_componentId[root] != root) {
  //   _componentId[root] = _componentId[_componentId[root]];
  //   root = _componentId[root];
  // }
  // return root;

  // root pointer
  int root = p;
  int temp;

  while (_componentId[root] != root){
    root = _componentId[root];
  }
  while (_componentId[p] != p) {
    temp = _componentId[p];
    _componentId[p] = root;
    p = temp;
  }
  return root;
  
}
bool PathCompressionWeightedUnion::find(int q, int p) {
  q = findRoot(q);
  p = findRoot(p);
  return (q == p);
}

void PathCompressionWeightedUnion::union_(int q, int p) {
  q = findRoot(q);
  p = findRoot(p);
  if (_componentSize[q] > _componentSize[p]){
    _componentId[p] = q;
    _componentSize[q] = _componentSize[q] + _componentSize[p];
  } else {
    _componentId[q] = p;
    _componentSize[p] = _componentSize[q] + _componentSize[p];
  }

}

#endif