#pragma once
#include <cassert>
#include <string>

template <class T>
class Array {

 public:

    Array(int len=10)                  : len_(len), data_(new T[len]) {}
    ~Array()                           { delete[] data_; }
    int len() const                    { return len_; }
    const T& operator[](int i) const   { return data_[check(i)]; }
          T& operator[](int i)         { return data_[check(i)]; }

    // Overload the << operator to print the array
    //friend std::ostream& operator<< <> (std::ostream& o, const Foo<T>& x);

 private:

    int len_;
    T* data_;
    int check(int i) const;
};

template <class T>
inline int Array<T>::check(int i) const {
    assert(i >= 0 || i < len_);
    return i;
}