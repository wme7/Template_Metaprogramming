#include <iostream>
#include "header.h"

#define DEPTH 8

struct var {
    static const long double value;
};

const long double var::value = series::PI / 4;

int main(int argc, char *argv[]) {

    bool ok = true;
    
    std::cout << "     arg   = " << var::value << "\n";
    std::cout << "sin( arg ) = " << series::sin<var,DEPTH>::value << "\n";
    std::cout << "cos( arg ) = " << series::cos<var,DEPTH>::value << "\n";
    std::cout << "tan( arg ) = " << series::tan<var,DEPTH>::value << "\n";

    return ok;
}
