# pragma once

template <bool Condition = false>
struct AlternatingType{
  using type = int;
};

template <>
struct AlternatingType<true> {
  using type = float;
};

template <bool Condition>
using Alternating = typename AlternatingType<Condition>::type;