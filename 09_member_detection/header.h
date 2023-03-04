# pragma once

template<class...>
using void_t = void;

// Primary template
template<class, class = void>
struct has_meaning : std::false_type{};

// Template specialization
template<class T>
struct has_meaning<T,void_t<typename T::meaning>> : std::true_type{};