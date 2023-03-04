
#include <iostream>
#include <chrono>
#include <string>

#include "crtp_interface.h"
#include "normal_interface.h"

template <class T, class S>
void Benchmark(T& object, S function, const std::string& name)
{
  // Get starting timepoint
  auto start = std::chrono::high_resolution_clock::now();

  // Execute the function
  function(&object);

  // Get ending timepoint
  auto stop = std::chrono::high_resolution_clock::now();

  // Calculate time and output resutl
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
  std::cout << "duration.count() : " << duration.count() << std::endl;
}

int main()
{
  NormalImplemented object1;
  Benchmark(object1, RunNormal, "Normal Interface");

  CRTPImplemented object2;
  Benchmark(object2, RunCRTP<CRTPImplemented>, "CRTP Interface");

  // If everything goes well
  return 0;
}

