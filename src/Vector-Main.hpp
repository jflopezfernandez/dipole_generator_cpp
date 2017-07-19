#ifndef VECTOR_MAIN_HPP
#define VECTOR_MAIN_HPP

#include <ostream>


class Vector {
public:
	double v[3];
	
public:
	Vector();
	
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

#endif // VECTOR_MAIN_HPP
