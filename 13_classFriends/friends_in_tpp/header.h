#pragma once

#include <iostream>

// Solution Part 1:
// ----------------
// The solution is to convince the compiler while it is
// examining the class body proper that the operator+ and
// operator<< functions are themselves templates.
// There are several ways to do this; one simple approach
// is pre-declare each template friend function above the
// definition of template class Foo:

template <class T> class Foo;  // pre-declare the template class itself
template <class T> Foo<T> operator+(const Foo<T>& lhs, const Foo<T>& rhs);
template <class T> std::ostream& operator<<(std::ostream& o, const Foo<T>& x);

// Solution Part 2:
// ----------------
// Also you add <> in the friend lines, as shown:

template <class T>
class Foo {

 public:
  Foo(const T& value);
  T value();

  friend Foo<T> operator+ <> (const Foo<T>& lhs, const Foo<T>& rhs);
  friend std::ostream& operator<< <> (std::ostream& o, const Foo<T>& x);

 private:
  T value_;
};

#include "header.tpp"