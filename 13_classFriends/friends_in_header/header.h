#pragma once

#include <iostream>

// Note:
// -----
// In this solution we define the friend function within 
// the class body at the same moment you declare it to be a friend.

template <class T>
class Foo {

 public:
  Foo(const T& value = T()) : value_(value) {}
  T value() { return value_; }

  friend Foo<T> operator+(const Foo<T>& lhs, const Foo<T>& rhs) {
    return Foo<T>(lhs.value_ + rhs.value_);
  };
  friend std::ostream& operator<<(std::ostream& o, const Foo<T>& x) {
    return o << x.value_;
  };

 private:
  T value_;
};