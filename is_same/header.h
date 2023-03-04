# pragma once

// General case
template<typename T, typename U>
struct is_same {
  static constexpr bool value = false;
};

// Specialization
template<typename T>
struct is_same<T,T> {
  static constexpr bool value = true;
};