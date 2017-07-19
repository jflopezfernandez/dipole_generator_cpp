//
// Created by admin on 7/17/2017.
//

#include "Main.hpp"


namespace DEBUG {
    void printConstants() {
        std::cout << "PI: " << PI<1>::value << '\n';
        std::cout << "TOL: " << TOL<1>::value << '\n';
        std::cout << "ETA: " << ETA<1>::value << '\n';
        std::cout << "GCUT: " << GCUT<1>::value << '\n';
        std::cout << "GCUT_SQ: " << GCUT_SQ<1>::value << '\n';
        std::cout << "ETA4: " << ETA4<1>::value << '\n';
    }
}