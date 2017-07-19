//
// Created by admin on 7/17/2017.
//

#include "Main.hpp"


std::ostream& operator<<(std::ostream& stream, const Point3D& p)
{
    stream << "(" << p.x << "," << p.y << "," << p.z << ")";

    return stream;
}


bool operator==(const Point3D& a, const Point3D& b)
{
    if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z))
        return true;
    else
        return false;
}