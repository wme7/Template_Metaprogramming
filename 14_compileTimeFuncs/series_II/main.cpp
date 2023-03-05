#include <iostream>
#include "header.h"

int main(int argc,char** argv) {

    double phs =0;
    double stp = math::two_pi_v/100.0;

    for(int i = 0;i<100;++i) {
        std::cout<<math::sin(phs)<<std::endl;
        phs+=stp;
    }
    
    return 0;
}
