#include <iostream>
#include "header.h"

int main(int, char**) {

  bool ok = true; 

  Foo<int> lhs(1);
  Foo<int> rhs(2);
  Foo<int> result = lhs + rhs;
  std::cout << result << "\n";
  ok &= (result.value() == 3); std::cout << " test : " << ok << "\n";

  return ok;
}
