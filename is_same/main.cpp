#include <iostream>
#include <type_traits>
#include "header.h"

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run
 
int main()
{
  std::cout << is_same<int,double>::value << "\n";
  std::cout << is_same<int,float>::value << "\n";
  std::cout << is_same<int,int>::value << "\n";

  std::cout << std::is_same<int,double>::value << "\n";
  std::cout << std::is_same<int,float>::value << "\n";
  std::cout << std::is_same<int,int>::value << "\n";

  return 0;
}