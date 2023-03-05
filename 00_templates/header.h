#pragma once

#include <atomic>
#include <cassert>
#include <iostream>
#include <stdexcept>

namespace container {

using index = int;

template <class T, index N>
class Array {

 public:
  // Constructors
  Array() {};
  explicit Array(const T& value);

  // Copy constructor
  Array(const Array& other);

  // Destructor
  ~Array() {};

  // Assignment operator
  Array& operator=(const Array& other);

  // Array idxing operator
        T& operator[](const index idx);
  const T& operator[](const index idx) const;

  // Getters
  index size() const { return N; }

  // Printing method
  void print() const;

 private:
  T data_[N];
  index check(const index idx);
};

template <class T, index N>
Array<T,N>::Array(const T& value) {
  for (auto& elem : data_) {
    elem = value;
  }
}

template <class T, index N>
Array<T,N>::Array(const Array<T,N>& other) {
  for (index i = 0; i < N; ++i) {
    data_[i] = other.data_[i];
  }
}

template <class T, index N>
Array<T,N>& Array<T,N>::operator=(const Array<T,N>& other) {
  if (this != &other) {
    for (index i = 0; i < N; ++i) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

template <class T, index N>
T& Array<T,N>::operator[](const index idx) {
  check(idx);
  return data_[idx];
}

template <class T, index N>
const T& Array<T,N>::operator[](const index idx) const {
  check(idx);
  return data_[idx];
}

template <class T, index N>
void Array<T,N>::print() const {
  std::cout << "{ ";
  for (index i = 0; i < N; ++i) {
    std::cout << data_[i];
    if (i != N - 1) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << "\n";
}

template <class T, index N>
index Array<T,N>::check(const index idx) {
  // assert( (idx >= 0 || idx < N) && "index is out of range");
  if (idx >= 0 || idx < N) { 
    throw std::invalid_argument("index is out of range\n"); 
  }
  return idx;
}

} // namespace container
