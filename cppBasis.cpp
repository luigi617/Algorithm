#include <iostream>
using namespace std;

// pass by value: a and x are separated variables
void fun1(int a){
    a=10;
}
// pass by reference: a and x have the same entity -> same memory location
void fun2(int& a){
    a=10;
}
// pass by pointer: a points at the memory of x
void fun3(int* a){
    *a=10;
}

void cppBasisDescription(){
    int x;
    int *ptr;
    ptr = &x;

    int y = 50;
    cout << y << '-';
    fun1(y);
    cout << y << endl; // 50 - 50

    int z = 50;
    cout << z << '-';
    fun2(z);
    cout << z << endl; // 50 - 10

    int j = 50;
    cout << j << '-';
    fun3(&j);
    cout << j << endl; // 50 - 10
}

