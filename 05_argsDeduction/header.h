# pragma once

template <class T> struct dont_deduce { using type = T; };
template <class T> using dont_deduce_t = typename dont_deduce<T>::type;