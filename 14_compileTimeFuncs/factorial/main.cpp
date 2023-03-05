#include <iostream>
#include "header.h"

int main(int, char**) {

    bool ok = true;
    
    const int n = 5;
    int ref = 1 * 2 * 3 * 4 * 5;
    std::cout << "test C-function : " << (factorial(n) == ref) << "\n";
    std::cout << "test  meta-func : " << (Factorial<n>::value == ref) << "\n";

    return ok;
}
