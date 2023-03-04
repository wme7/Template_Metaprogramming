#include "myTemplate.h"

template <class T>
T MyTemplate<T>::f(T t) { return t + 1; }

// Explicit instantiation of the template class MyTemplate<int>
template class MyTemplate<int>;