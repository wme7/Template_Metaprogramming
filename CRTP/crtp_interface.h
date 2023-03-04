#ifndef CRTP_H_
#define CRTP_H_

#include <iostream>
#include <cstring>

template <class Derived> 
class CRTPInterface 
{
public:
  void Count(size_t n) { static_cast<Derived *>(this)->Count(n); }
  size_t GetValue() { return static_cast<Derived *>(this)->GetValue(); }
};

class CRTPImplemented : public CRTPInterface<CRTPImplemented> 
{
public:
  CRTPImplemented() : counter(0) {}

  void Count(size_t n) { counter += n; }
  size_t GetValue() { return counter; }

private:
  size_t counter;
};

template<class T>
void RunCRTP(CRTPInterface<T>* obj)
{
  const size_t N = 40000;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < i; j++) {
      obj->Count(j);
    }
  }
  std::cout << "obj->GetValue() : " << obj->GetValue() << std::endl;
}

#endif // CTRP_H_
