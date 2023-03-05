#include <iostream>
#include "header.h"

int main() {

  bool ok = true;

  // Test the Array class
  container::Array<int, 5> a(3);
  container::Array<int, 5> b;

  std::cout << "       a : "; a.print();
  b = a;
  std::cout << "   b = a : "; b.print();
  b[2] = 7;
  std::cout << "b[2] = 7 : "; b.print();
  
  try {
      std::cout << b[5] << "\n";
  } catch (const std::out_of_range& e) {
      std::cerr << e.what() << "\n";
  }
  
  return ok;
}
