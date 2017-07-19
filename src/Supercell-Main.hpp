#ifndef SUPERCELL_MAIN_HPP
#define SUPERCELL_MAIN_HPP

#include "Template-Constants.hpp"

#include "Supercell-Dot.hpp"
#include "Supercell-Wire.hpp"
#include "Supercell-Film.hpp"
#include "Supercell-Bulk.hpp"


//int CELL_VOLUMEf(int a[3][3]);

void CalculateReciprocalLatticeVectors(double a[][3], double b[][3]);


#endif // SUPERCELL_MAIN_HPP
