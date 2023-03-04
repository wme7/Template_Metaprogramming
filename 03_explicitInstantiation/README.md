# Understanding the importance of explicit template instantiations

Following discussion from : [stack overflow](https://stackoverflow.com/questions/2351148/explicit-template-instantiation-when-is-it-used)

Explicit instantiation mainly allow us to
1. **Save (re-)compilation time** :
 By removing the definitions from headers, it prevents intelligent build systems from rebuilding includers on every change to those templates.
2. **Prevent object redefinition** : 
 thus, again saving time and output (executable/library) size.

## How is removing definitions from header acomplish this?

Explicit instantiation allows you to leave definitions in the .cpp file.

When the d7efinition is on the header and you modify it, an intelligent build system would recompile all includers, which could be dozens of files, possibly making incremental re-compilation after a single file change unbearably slow.

Putting definitions in .cpp files does have the downside that external libraries can't reuse the template with their own new classes, but "Remove definitions from included headers but also expose templates an external API" below shows a workaround.

## How to avoid object redefinition?

Let us understand the basic problem : 

If you just completely define a template on a header file, every single compilation unit that includes that header ends up compiling its own implicit copy of the template for every different template argument usage made.

This means a lot of useless disk usage and compilation time.

## Example

A traditional problem formulation without any instantiation of a templated structure/class defined on a header:

main.cpp
```cpp
#include <iostream>
#include "myTemplate.h"
#include "notmain.h"

int main() {
    std::cout << notmain() + MyTemplate<int>().f(1) << std::endl;
}
```
myTemplate.h
```cpp
#pragma once

template<class T>
struct MyTemplate {
    T f(T t) { return t + 1; }
};
```
notmain.h
```cpp
#pragma once

int notmain();
```
notmain.cpp
```cpp
#include "myTemplate.h"
#include "notmain.h"

int notmain() { return MyTemplate<int>().f(1); }
```
Compile and view symbols with `nm`:
```bash
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o notmain.o notmain.cpp
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o main.o main.cpp
g++    -Wall -Wextra -std=c++11 -pedantic-errors -o main.out notmain.o main.o
echo notmain.o
nm -C -S notmain.o | grep MyTemplate
echo main.o
nm -C -S main.o | grep MyTemplate
```
Output:

```bash
notmain.o
0000000000000000 0000000000000013 W MyTemplate<int>::f(int)
main.o
0000000000000000 0000000000000013 W MyTemplate<int>::f(int)
```
So we see that a separate section is generated for every single method instantiation, and that each of of them takes of course space in the object files.

From man `nm`, we see that `W` means **weak symbol**, which GCC chose because this is a template function.

The reason it doesn't blow up at link time with multiple definitions is that the linker accepts multiple weak definitions, and just picks one of them to put in the final executable, and all of them are the same in our case, so all is fine.

The numbers in the output mean:

    `0000000000000000`: address within section. This zero is because templates are automatically put into their own section
    `0000000000000013`: size of the code generated for them

We can see this a bit more clearly with:
```bash
objdump -S main.o | c++filt
```
which ends in:

```bash
main.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   53                      push   %rbx
   5:   48 83 ec 18             sub    $0x18,%rsp
   9:   e8 00 00 00 00          callq  e <main+0xe>
   e:   89 c3                   mov    %eax,%ebx
  10:   48 8d 45 ef             lea    -0x11(%rbp),%rax
  14:   be 01 00 00 00          mov    $0x1,%esi
  19:   48 89 c7                mov    %rax,%rdi
  1c:   e8 00 00 00 00          callq  21 <main+0x21>
  21:   01 d8                   add    %ebx,%eax
  23:   89 c6                   mov    %eax,%esi
  25:   bf 00 00 00 00          mov    $0x0,%edi
  2a:   e8 00 00 00 00          callq  2f <main+0x2f>
  2f:   be 00 00 00 00          mov    $0x0,%esi
  34:   48 89 c7                mov    %rax,%rdi
  37:   e8 00 00 00 00          callq  3c <main+0x3c>
  3c:   b8 00 00 00 00          mov    $0x0,%eax
  41:   48 83 c4 18             add    $0x18,%rsp
  45:   5b                      pop    %rbx
  46:   5d                      pop    %rbp
  47:   c3                      retq   

0000000000000048 <__static_initialization_and_destruction_0(int, int)>:
  48:   55                      push   %rbp
  49:   48 89 e5                mov    %rsp,%rbp
  4c:   48 83 ec 10             sub    $0x10,%rsp
  50:   89 7d fc                mov    %edi,-0x4(%rbp)
  53:   89 75 f8                mov    %esi,-0x8(%rbp)
  56:   83 7d fc 01             cmpl   $0x1,-0x4(%rbp)
  5a:   75 27                   jne    83 <__static_initialization_and_destruction_0(int, int)+0x3b>
  5c:   81 7d f8 ff ff 00 00    cmpl   $0xffff,-0x8(%rbp)
  63:   75 1e                   jne    83 <__static_initialization_and_destruction_0(int, int)+0x3b>
  65:   bf 00 00 00 00          mov    $0x0,%edi
  6a:   e8 00 00 00 00          callq  6f <__static_initialization_and_destruction_0(int, int)+0x27>
  6f:   ba 00 00 00 00          mov    $0x0,%edx
  74:   be 00 00 00 00          mov    $0x0,%esi
  79:   bf 00 00 00 00          mov    $0x0,%edi
  7e:   e8 00 00 00 00          callq  83 <__static_initialization_and_destruction_0(int, int)+0x3b>
  83:   90                      nop
  84:   c9                      leaveq 
  85:   c3                      retq   

0000000000000086 <_GLOBAL__sub_I_main>:
  86:   55                      push   %rbp
  87:   48 89 e5                mov    %rsp,%rbp
  8a:   be ff ff 00 00          mov    $0xffff,%esi
  8f:   bf 01 00 00 00          mov    $0x1,%edi
  94:   e8 af ff ff ff          callq  48 <__static_initialization_and_destruction_0(int, int)>
  99:   5d                      pop    %rbp
  9a:   c3                      retq   

Disassembly of section .text._ZN10MyTemplateIiE1fEi:

0000000000000000 <MyTemplate<int>::f(int)>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 89 7d f8             mov    %rdi,-0x8(%rbp)
   8:   89 75 f4                mov    %esi,-0xc(%rbp)
   b:   8b 45 f4                mov    -0xc(%rbp),%eax
   e:   83 c0 01                add    $0x1,%eax
  11:   5d                      pop    %rbp
  12:   c3                      retq   
```

and `_ZN10MyTemplateIiE1fEi` is the mangled name of `MyTemplate<int>::f(int)>` which `c++filt` decided not to unmangle.

## Problem solutions

To solve we explore several solutions:

### Solution 0 : explicit specialization

Produce a template specialization for `struct MyTemplate` explicitly for type `int`. However, a template specialization has **no benefit what-so-ever** in improving this situation. Thus. *only a true **explicit instantiation** of the struct/class would do*. 

### Solution 1 : explicit instantiation

keep definition on `h` and add `extern template` on `h` for types which are going to be explicitly instantiated.

As explained at: [using extern template (C++11)](https://stackoverflow.com/questions/8130602/using-extern-template-c11/59614090#59614090), using `extern template` (C++11) prevents a completely defined template from being instantiated by compilation units, except for our explicit instantiation. This way, only our explicit instantiation will be defined in the final objects:

myTemplate.h
```cpp
#pragma once

template<class T>
struct MyTemplate {
    T f(T t) { return t + 1; }
};

// Extern template declaration to prevent compiler
extern template class MyTemplate<int>;
```
mytemplate.cpp
```cpp
#include "mytemplate.hpp"

// Explicit instantiation required just for int.
template class MyTemplate<int>;
```
We now compile as
```bash
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o notmain.o notmain.cpp
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o myTemplate.o myTemplate.cpp
g++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o main.o main.cpp
g++    -Wall -Wextra -std=c++11 -pedantic-errors -o main.out notmain.o myTemplate.o main.o
echo notmain.o
nm -C -S notmain.o | grep MyTemplate
echo main.o
nm -C -S main.o | grep MyTemplate
echo myTemplate.o
nm -C -S myTemplate.o | grep MyTemplate
```
which produces the follosing output:

```bash
notmain.o
                 U MyTemplate<int>::f(int)
main.o
                 U MyTemplate<int>::f(int)
myTemplate.o
0000000000000000 0000000000000013 W MyTemplate<int>::f(int)
```
so we see have only `mytemplate.o` has a compilation of `MyTemplate<int>` as desired, while notmain.o and main.o don't because `U` means undefined.

However, this approach has the following downsides:

- the definition stays in the header, making single file change recompiles to that header possibly slow
- if you are header only library, you force external projects to do their own explicit instantiation. *If you are not a header-only library --like any typical shared/static library-- this solution is likely the best.*
- if the template type is defined in your own project and not a built-in like `int`, it seems that you are forced to add the include for it on the header, a *forward declaration* is not enough: `extern template` & *incomplete types*. This increases header dependencies a bit.

### Solution 2 : another explicit instantiation

moving the definition on the cpp file, leave only declaration on hpp, i.e. modify the original example to be:

myTemplate.h

```cpp
#pragma once

template<class T>
struct MyTemplate {
    T f(T t);
};
```
myTemplate.cpp
```cpp
#include "mytemplate.hpp"

template<class T>
T MyTemplate<T>::f(T t) { return t + 1; }

// Explicit instantiation.
template class MyTemplate<int>;
```
The compilation again produces the following output:
```bash
notmain.o
                 U MyTemplate<int>::f(int)
main.o
                 U MyTemplate<int>::f(int)
myTemplate.o
0000000000000000 0000000000000013 W MyTemplate<int>::f(int)
```

Downside: external projects can't use your template with their own types. Also you are forced to explicitly instantiate all types. 
- But maybe this is an **upside** since then programmers won't forget. ;D

Happy Coding !! -- MD