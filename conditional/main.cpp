#include <iostream>
#include <typeinfo>
#include "header.h"

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run

int main() {
  Alternating<false> var1 = 1;
  Alternating<true> var2 = 2.0f; 

  std::cout << typeid(var1).name() << "\n";
  std::cout << typeid(var2).name() << "\n";

  return 0;
}