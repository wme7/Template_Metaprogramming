# Proxy template technique

Based on this [FAQ](https://isocpp.org/wiki/faq/templates#template-of-template)

## Problem definition:

the goal is to create a template `container<>`, but having the template parameter-list include some particular type of std::vector<T> or std::list<T> or some other (possibly non-standard) container to actually store the values.

Here’s one way to do that:

header.h
```cpp
template<typename UNDERLYING>
class container {

 public:

  // typename value_type is the type of the values within class container 
  using value_type = typename UNDERLYING::value_type;

  void insert(const typename value_type &x)
  {
    // ...code to insert x into data_...
  }
  // ...

 private:

  UNDERLYING data_;

};
```
main.cpp
```cpp
#include <list>
#include <vector>
#include "header.h"

int main {

  Foo<std::vector<int> > x;
  Foo<std::list<double> > y;

  return 0;
}
```
Now, if you want to allow your users to provide you with an underlying container that does not necessarily have a `value_type` typedef (such as some container from a third party), you could provide the value-type explicitly:

header.h
```cpp
template<class T, class UNDERLYING>
class container {

 public:

  // typename value_type is the type of the values within class container 
  using value_type = T;

  void insert(const typename value_type &x)
  {
    // ...code to insert x into data_...
  }
  // ...

 private:

  UNDERLYING data_;

};
```

main.cpp
```cpp
#include <list>
#include <vector>
#include "header.h"

int main {

  Foo<int, std::vector<int> > x;
  Foo<double, std::list<double> > y;

  return 0;
}
```

Now, `std::vector` template can have, does have, more than one argument. However, you're required to make them match in the number, order, and nature — type/non-type, etc.

It is possible, however, to “cheat” your way out of specifying all those arguments and use the defaults? The answer is yes, using a technique called the **proxy template**  [technique](./header.h).
