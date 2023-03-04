//
// The Curiously recurring template pattern
//
// Based on:
// https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/

template <class Derived> class Base 
{
public:
  Base() = default;

  void DoSomething() {
    Derived &derived = static_cast<Derived &>(*this);
    // use derived...
  }

private:
};

class Derived : public Base<Derived> 
{
public:
  Derived() = default;
};