#ifndef MATRIX_HPP
#define MATRIX_HPP


#include <ostream>


class Matrix {
public:
	double m[3][3];

public:
	Matrix();
	Matrix(const double& d);
	Matrix(const double& a, const double& b, const double& c);
	
	void set(const double& d);
	void set(const double& a, const double& b, const double& c);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};


#endif // MATRIX_HPP
