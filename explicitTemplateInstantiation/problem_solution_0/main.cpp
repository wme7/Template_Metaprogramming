#include <iostream>
#include "myTemplate.h"
#include "notmain.h"

// compile as : sh compile.sh

int main() {
    std::cout << notmain() + MyTemplate<int>().f(1) << std::endl;
}
