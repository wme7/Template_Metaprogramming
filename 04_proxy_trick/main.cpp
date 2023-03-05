#include <iostream>
#include <list>
#include <typeinfo>
#include "header.h"

// Problem definition:

int main() {
    
    bool ok = true;
    
    vector<int> wvi; wvi.push_back(1);
    list<double> wdi; wvi.push_back(1);

    container<int, vector> cvi; cvi.push_back(1);
    container<double, list> cld; cld.push_back(1.0);
    
    std::cout << typeid(cvi).name() << "\n";
    std::cout << typeid(cld).name() << "\n";

    return ok;
}
