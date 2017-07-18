//
// Created by admin on 7/17/2017.
//

#include "Main.hpp"


std::ostream& operator<<(std::ostream& stream, const Vector3D& v)
{
    if (v.normalized) {
        stream << v.head;
    } else {
        stream << v.tail << " --> " << v.head;
    }
}


bool operator==(const Vector3D& a, const Vector3D& b)
{
    if ((a.head == b.head) && (a.tail == b.tail))
        return true;
    else
        return false;
}