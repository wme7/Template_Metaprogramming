// Foo's definitions

template <class T>
Foo<T>::Foo(const T& value) : value_(value) {}

template <class T>
T Foo<T>::value() {
  return value_;
}

template <class T>
Foo<T> operator+(const Foo<T>& lhs, const Foo<T>& rhs) {
  return Foo<T>(lhs.value_ + rhs.value_);
}

template <class T>
std::ostream& operator<<(std::ostream& o, const Foo<T>& x) {
  return o << x.value_;
}