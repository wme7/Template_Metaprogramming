#include <iostream>
#include <streambuf>
#include "header.h"

int main() {
  // Create an array of size 5
  Array<int, 5> my_array;

  // Insert some values into the array
  my_array.fill(1);

  // Print out the values in the array
  std::cout << "Values in array: ";
  for (const auto& val : my_array) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // Check if the array is empty
  if (my_array.empty()) {
    std::cout << "Array is empty" << std::endl;
  } else {
    std::cout << "Array is not empty" << std::endl;
  }

  // Change the array values
  std::fill(my_array.begin(), my_array.end(), 4);

  // Print out the updated values in the array
  std::cout << "Values in array: ";
  for (const auto& val : my_array) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // Check the size of the array
  std::cout << "Array size: " << my_array.size() << std::endl;

  return 0;
}
