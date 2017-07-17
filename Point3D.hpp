//
// Created by admin on 7/17/2017.
//

#ifndef DIPOLE_GENERATOR_CPP_POINT3D_HPP
#define DIPOLE_GENERATOR_CPP_POINT3D_HPP


#include <iostream>
#include <ostream>



struct Point3D {
    int x,
        y,
        z;

    Point3D() : x(0), y(0), z(0) { }
    Point3D(const int& a, const int& b, const int& c) : x(a), y(b), z(c) { }

    friend std::ostream& operator<<(std::ostream& stream, const Point3D& p);
};

bool operator==(const Point3D& a, const Point3D& b);


#endif //DIPOLE_GENERATOR_CPP_POINT3D_HPP
