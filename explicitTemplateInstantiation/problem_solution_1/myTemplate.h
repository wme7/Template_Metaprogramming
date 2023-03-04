# pragma once

template<class T>
struct MyTemplate {
    T f(T t) { return t + 1; }
};

extern template class MyTemplate<int>;