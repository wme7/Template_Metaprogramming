# A simple container example in C++17

I retake the Array template created in the previous example and turn it into a full container class.

Refs.: 
1. [CS361](https://www.cs.odu.edu/~zeil/cs361/latest/Directory/outline/), Spring 2023.
2. [Writing a custom iterator in modern C++](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)


From [cpluplus.com](https://cplusplus.com/reference/stl/) :

A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

Containers replicate structures very commonly used in programming: dynamic arrays (vector), queues (queue), stacks (stack), heaps (priority_queue), linked lists (list), trees (set), associative arrays (map)...

Many containers have several member functions in common, and share functionalities. The decision of which type of container to use for a specific need does not generally depend only on the functionality offered by the container, but also on the efficiency of some of its members (complexity). This is especially true for sequence containers, which offer different trade-offs in complexity between inserting/removing elements and accessing them.

stack, queue and priority_queue are implemented as container adaptors. Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes (such as deque or list) to handle the elements. The underlying container is encapsulated in such a way that its elements are accessed by the members of the container adaptor independently of the underlying container class used.

## 1. What is generic programming?

The combination of templates and iterators, combined with a wider range of container types, brings us to generic programming, an important and pervasive style of coding in C++.

## 2. What are template and Iterators?

- *Templates* are a mechanism for writing algorithmic patterns that can be applied to a wide variety of different data types.
- *Iterators* are a data abstraction for the notion of a position within a container of data. Iterators allow us to express many simple algorithms in a simple form, regardless of whether the underlying container is an array, a linked list, a tree, or some other data structure.

Templates and iterators are often used together to provide patterns for code that can be applied to a wide range of underlying data structures.

