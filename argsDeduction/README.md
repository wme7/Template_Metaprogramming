# Example to show how to avoid the deduction of a template argument 


Assume the following situation:

A function with two arguments, of type `T` and type `M`. Namely: 
```cpp
template<class T>
void do_stuff(T a, M b);
```
However, `b` can be implicitly converted to `a` but the opposite should be untrue.

To achieve this let us warp `b` in a *non-deduced context*. That way, only `a`-type will be deduced and `b` must be converted to that type.

```cpp
template <class T> struct dont_deduce { using type = T; };
template <class T> using dont_deduce_t = typename dont_deduce<T>::type;

template<class T>
void do_stuff(T a, dont_deduce_t<T> b);
```