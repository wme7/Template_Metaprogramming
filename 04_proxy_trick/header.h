#pragma once

#include <vector>
#include <list>

// std::vector wrapper
template<class T>
class vector {
  public :
    using type = std::vector<T>;
    void push_back(T v) { data_.push_back(v); };
  private :
    type data_;
};

// std::list wrapper
template<class T>
struct list {
  public :
    using type = std::list<T>;
    void push_back(T v) { data_.push_back(v); }
  private :
    type data_;
};

// proxy container
template <class T, template<typename> class STL> 
class container {
  public :
    using type = typename STL<T>::type; // trick to use a proxy
    void push_back(T v) { data_.push_back(v); }
  private :
    STL<T> data_;
};

