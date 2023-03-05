#pragma once

template <class T>
class Stack
{
  public:
    Stack(int size=10) : size_(size) {}
    ~Stack()           { delete [] data_; }

  private:
    int size_;
    int top_;
    T* data_;
};