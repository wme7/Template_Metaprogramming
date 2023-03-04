#include <iostream>
#include <typeinfo>
#include "header.h"

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run

template <class T>
void do_stuff_v1(T a, T b){
  std::cout << " a: " << typeid(a).name() 
            << " b: " << typeid(b).name() << "\n";
}

template <class T>
void do_stuff_v2(bool a, T b){
  std::cout << " a: " << typeid(a).name() 
            << " b: " << typeid(b).name() << "\n";
}

template <class T>
void do_stuff_v3(T a, dont_deduce_t<T> b){
  std::cout << " a: " << typeid(a).name() 
            << " b: " << typeid(b).name() << "\n";
}

int main() {
  
  do_stuff_v1(1,1);
  do_stuff_v2(true, 1);
  do_stuff_v3(1.0f, 2.0f);
  do_stuff_v3(1.0f, false); 

  return 0;
}