# An Array Template Class

Here a simple implementation of an array class written using c++17 and CMake is presented. 

Example based on [CS361](https://www.cs.odu.edu/~zeil/cs361/latest/Directory/outline/) lectures.

The following some personal notes of what I have learn while doing this prototype:


## 1.Template class vs. class of templates?

In C++, there is no such thing as a template class. There are only class templates.

That is, literally, templates for creating classes.

`template <typename T> std::vector<T>` is not a class, for example. It is a template from which, if you supply an appropriate `T`, a class can be generated.

Of course, people often say ''template class'' when they mean ''class template'', so there's no real difference. But formally, one exists in C++, and the other does not.


## 2. `assert` vs. (`throw`) exceptions?

My rule of thumb is the follwing

- Exceptions are used for run-time error conditions (IO errors, out of memory, can't get a database connection, etc.).

- Assertions are used for coding errors (this method doesn't accept nulls, and the developer passed one anyway).

In otther words, for libraries with public classes, *throw exceptions on the public methods* (because it makes sense to do so). *Assertions are used to catch **YOUR mistakes***, not theirs.

Moreover, the principle is that you use assertions for conditions that should NEVER happen, for conditions that should NEVER make it into production code. These conditions absolutely must fail during unit testing, This is why CMake deactivate all assertions when Release build type is selected.