# pragma once

template<typename T>
struct remove_const {
  using type = T;
};

template<typename T>
struct remove_const<T const> {
  using type = T;
};