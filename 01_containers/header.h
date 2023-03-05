#pragma once

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T, std::size_t N>
class Array {

public:
  // Constructors
  Array() = default;
  Array(std::initializer_list<T> initList) {
      if (initList.size() != N) {
          throw std::invalid_argument("Invalid initializer list size");
      }
      std::size_t i = 0;
      for (auto& elem : initList) {
          data_[i++] = elem;
      }
  }
  
  // Access operators
  T& operator[](std::size_t i) {
      if (i >= N) {
          throw std::out_of_range("Index out of range");
      }
      return data_[i];
  }
  
  const T& operator[](std::size_t i) const {
      if (i >= N) {
          throw std::out_of_range("Index out of range");
      }
      return data_[i];
  }
  
  // // Iterator support
  // T* begin() noexcept { return data_; }
  // T* end() noexcept { return data_ + N; }
  // const T* begin() const noexcept { return data_; }
  // const T* end() const noexcept { return data_ + N; }
  // const T* cbegin() const noexcept { return data_; }
  // const T* cend() const noexcept { return data_ + N; }
  
  // Capacity
  constexpr std::size_t size() const noexcept { return N; }
  constexpr bool empty() const noexcept { return false; }
  
  // Modifiers
  void fill(const T& value) { for (auto& elem : data_) elem = value; }
  void swap(Array& other) noexcept { std::swap(data_, other.data_); }
  
  // Non-member functions
  friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
      os << "[";
      for (std::size_t i = 0; i < N; ++i) {
          os << arr.data_[i];
          if (i != N - 1) {
              os << ", ";
          }
      }
      os << "]";
      return os;
  }
    
  struct Iterator 
  {
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = int;
    using pointer           = int*;
    using reference         = int&;

    Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    Iterator& operator++() { m_ptr++; return *this; }  
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };  

  private:
    pointer m_ptr;
  };

  Iterator begin() noexcept { return Iterator( data_); }
  Iterator end()   noexcept { return Iterator( data_ + N); }

private:
  T data_[N];
};
