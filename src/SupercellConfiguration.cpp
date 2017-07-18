//
// Created by admin on 7/17/2017.
//

#include "Main.hpp"


SupercellConfiguration::SupercellConfiguration(const int& x, const int& y, const int& z, const int& t)
{
    std::cout << "[DEBUG] Generating Supercell Configuration...\n";

    n1 = x;
    n2 = y;
    nz = z;

    type = static_cast<SUPERCELL_TYPE>(t);
}


void SupercellConfiguration::print() const
{
    std::cout << "Current Supercell Configuration Settings: \n";
    std::cout << "\tN1: " << n1 << '\n';
    std::cout << "\tN2: " << n2 << '\n';
    std::cout << "\tNZ: " << nz << '\n';

    std::cout << '\n';
}

