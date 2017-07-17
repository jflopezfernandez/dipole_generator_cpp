//
// Created by admin on 7/17/2017.
//

#ifndef DIPOLE_GENERATOR_CPP_MATRIX3_HPP
#define DIPOLE_GENERATOR_CPP_MATRIX3_HPP

#include <iostream>
#include <ostream>

class Matrix3D {
private:
    int m[3][3];

public:
    Matrix3D();
    Matrix3D(const int& a, const int& b, const int& c);



    friend std::ostream& operator<<(std::ostream& stream, const Matrix3D& m);
};

Matrix3D generate_reciprocal_lattice_vectors(const Matrix3D& a);


#endif //DIPOLE_GENERATOR_CPP_MATRIX3_HPP
