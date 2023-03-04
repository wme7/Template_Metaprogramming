#include <iostream>
#include <type_traits>
#include "header.h"

// compile as : clang++ -o main.run main.cpp
//     run as : ./main.run

template <typename T>
using wanted_type = find_type<T,int,float,double,int const>;

int main()
{
    return 0;
}