//
// Created by admin on 7/17/2017.
//

#include "Main.hpp"


Matrix3D::Matrix3D()
{
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix3D::Matrix3D(const int& a, const int& b, const int& c)
{
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            if (i == j) {
                if (i == 0) m[i][j] = a;
                if (i == 1) m[i][j] = b;
                if (i == 2) m[i][j] = c;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

Matrix3D generate_reciprocal_lattice_vectors(const Matrix3D& a)
{
//    // TODO: Reciprocal lattice vector calculations
    Matrix3D b(ERROR, ERROR, ERROR);
////    b[0][0] = (a[1][1] * a[2][2]) - (a[2][1] * a[1][2]);
////    b[1][0] = (a[2][1] * a[0][2]) - (a[0][1] * a[2][2]);
////    b[2][0] = (a[0][1] * a[1][2]) - (a[1][1] * a[0][2]);
////
////    b[0][1] = (a[1][2] * a[2][0]) - (a[2][2] * a[1][0]);
////    b[1][1] = (a[2][2] * a[0][0]) - (a[0][2] * a[2][0]);
////    b[2][1] = (a[0][2] * a[1][0]) - (a[1][2] * a[0][0]);
////
////    b[0][2] = (a[1][0] * a[2][1]) - (a[2][0] * a[1][1]);
////    b[1][2] = (a[2][0] * a[0][1]) - (a[0][0] * a[2][1]);
////    b[2][2] = (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
////
////    double c = PI * 2.0;
////    double ci;
////
////    for (int i = 0; i < 3; i++) {
////        ci = c / (a[0][i] * b[0][i] + a[1][i] * b[1][i] + a[2][i] * b[2][i]);
////
////        b[0][i] = b[0][i] * ci;
////        b[1][i] = b[1][i] * ci;
////        b[2][i] = b[2][i] * ci;
////    }
//
//

    return b;
}

std::ostream& operator<<(std::ostream& stream, const Matrix3D& m)
{
    stream << '\n';

    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            stream << m.m[i][j] << " ";
        }
        stream << '\n';
    }

    return stream;
}