#include <iostream>
#include "header.h"

int main() {

  bool ok = true;

  ok &= Max(10, 15) == 15;          std::cout << "test1 : " << ok << "\n";
  ok &= Max('k', 's') == 's';       std::cout << "test2 : " << ok << "\n";
  ok &= Max(10.1f, 15.2f) == 15.2f; std::cout << "test3 : " << ok << "\n";
  ok &= Max(10.1, 15.2) == 15.2;    std::cout << "test3 : " << ok << "\n";

  // If all test are okß, then
  return ok;
}
