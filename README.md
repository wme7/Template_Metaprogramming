# CRTP

This is a C++ example that I used to learn about the **C**uriously **R**ecurrent **T**emplate **P**atterns (CRTP) works, and how it speeds up your my c++ codes.

Two versions of a simple example are created:
- The ''Normal'' inheritance code,
- The **CRTP**-version of the same code.

Verifications:
- Evaluate both codes *output* and *CPU time*
- Testing with `g++` and `clang++` compilers

### Compilers details

`g++ --version`

````shell
g++ (GCC) 8.5.0 20210514 (Red Hat 8.5.0-17)
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
````
`clang++ --version`

````shel
clang version 14.0.6 (Red Hat 14.0.6-1.module_el8.7.0+1198+0c3eb6e2)
Target: x86_64-redhat-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
````

## test 1

Compiling as:   `g++ -O3 main.cpp -o main.run`

````shell
mdiaz@foo:~$ ./main.run  
obj->GetValue() : 10665866680000
duration.count() : 1312283
obj->GetValue() : 10665866680000
duration.count() : 235683
````

## Test 2

Compiling as:  `clang++ -O3 main.cpp -o main.run`

````shell
mdiaz@foo:~$ ./main.run                      
obj->GetValue() : 10665866680000
duration.count() : 942045
obj->GetValue() : 10665866680000
duration.count() : 33
````

## Conclusion
- Using `gcc-8.5.0` and CRTP implementation, a speed up of 5.5X was observed.
- Using `clang-14.0.6` and CRTP implementation, a speed up of 28,546X was observed. 

(Incredible! but why?) 

I guess I'll be working with `clang` and using **CRTP** as my defuld `C++` style for now.

Refs: 
- Boccara, J. "The Curiously Recurring Template Pattern (CRTP)". Blog [Fluent C++](https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/), accessed on 09.12.2022 
- Sepiol, Z. "C++ Tutorial: How to use CRTP to speed up your code".  Video [YouTube](https://youtu.be/Srx4eiBdpdQ), accessed on 09.12.2022