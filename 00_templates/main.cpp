
#include <iostream>
#include "header.h"

int main()
{
  Array<int>           ai, bi;
  Array<float>         af, bf;
  Array<char>          ac, bc;
  Array<Array<int> >   aai, bai;
  
  std::cout << "ai.len()  : " << ai.len()  << std::endl;
  std::cout << "af.len()  : " << af.len()  << std::endl;
  std::cout << "ac.len()  : " << ac.len()  << std::endl;

  return 0;
}
