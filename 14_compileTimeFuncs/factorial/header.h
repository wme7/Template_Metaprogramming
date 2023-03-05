#pragma once

// C implementation of the factorial function
int factorial(const int &n) {
  int f = 1;
  for (int i=1; i<=n; ++i) {
    f *= i;
  }
  return f;
};

// Compile-time factorial function
template<int N>
struct Factorial {
    enum { value = N * Factorial<N-1>::value };
};
template<>
struct Factorial<1> {
    enum { value = 1 };
};