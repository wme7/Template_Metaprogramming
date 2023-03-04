#include <iostream>
#include <type_traits>
#include "header.h"

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run

void foo(void* p) { std::cout << "foo() called. it better not try to modify *p!\n"; }

template<typename T>
void  my_RemoveAdd (T *p) {
    foo( const_cast< typename remove_const<T>::type *> (p) );
}

template<typename T>
void  STD_RemoveAdd (T *p) {
    foo( const_cast< typename std::remove_const<T>::type *> (p) );
}
 
int main()
{
    const int *p;
    const int *q;
    my_RemoveAdd(p);
    STD_RemoveAdd(q);
}