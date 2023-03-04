#include <iostream>

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run

// Base case
void print() 
{
  std::cout << "I am an empty function and "
               "I am called at last.\n";
}

// Specialization
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
  std::cout << var1 << std::endl;

  print(var2...);
}

// Driver code
int main() 
{
  print(1, 2, 3.1416, "Pass my any number for arguments", "I will print");

  return 0;
}
