//
// Created by admin on 7/17/2017.
//

#ifndef DIPOLE_GENERATOR_CPP_VECTOR3D_HPP
#define DIPOLE_GENERATOR_CPP_VECTOR3D_HPP


#include "Point3D.hpp"

struct Vector3D {
    bool normalized = true;

    Point3D head;
    Point3D tail;

    Vector3D() : head(Point3D(0,0,0)), tail(Point3D(0,0,0)), normalized(true) { }
    Vector3D(const int& a, const int& b, const int& c) : head(Point3D(a,b,c)), tail(Point3D(0,0,0)), normalized(true) { }

    Vector3D(const Point3D& p) : head(p), tail(Point3D(0,0,0)), normalized(true) { }

    Vector3D(const int& x1, const int& y1, const int& z1, const int& x2, const int& y2, const int& z2)
            : head(Point3D(x2, y2, z2)), tail(Point3D(x1,y1,z1)), normalized(false) { }
    Vector3D(const Point3D& a, const Point3D& b) : head(b), tail(a), normalized(false) { }


    friend std::ostream& operator<<(std::ostream& stream, const Vector3D& v);
};


bool operator==(const Vector3D& a, const Vector3D& b);


#endif //DIPOLE_GENERATOR_CPP_VECTOR3D_HPP
