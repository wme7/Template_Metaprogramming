#ifndef NORMAL_H_
#define NORMAL_H_

#include <iostream>
#include <cstring>

class NormalInterface {
public:
  virtual void Count(size_t n) = 0;
  virtual size_t GetValue() = 0;
};

class NormalImplemented : public NormalInterface {
public:
  NormalImplemented() : counter(0) {}

  virtual void Count(size_t n) { counter += n; }

  virtual size_t GetValue() { return counter; }

private:
  size_t counter;
};

void RunNormal(NormalImplemented* obj) 
{
  const size_t N = 40000;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < i; j++) {
      obj->Count(j);
    }
  }
  std::cout << "obj->GetValue() : " << obj->GetValue() << std::endl;
}

#endif // NORMAL_H_