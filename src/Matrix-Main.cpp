
#include "Main.hpp"


Matrix::Matrix()
{
	std::cout << "[DEBUG: Default matrix constructor called...]\n";
}

Matrix::Matrix(const double& d)
{
	this->set(d);
}

Matrix::Matrix(const double& a, const double& b, const double& c)
{
	this->set(a,b,c);
}

void Matrix::set(const double& d)
{
	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			if (i == j) {
				m[i][j] = d;
			} else {
				m[i][j] = 0;
			}
		}
	}
}

void Matrix::set(const double& a, const double& b, const double& c)
{
	static int count = 0;
	double index;
	
		for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			if (i == j) {
				++count;
				
				switch (count) {
					case (0):
						index = a;
						break;
					case (1):
						index = b;
						break;
					case (2):
						index = c;
						break;
				}
				
				m[i][j] = index;
						
			} else {
				m[i][j] = 0;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			os << m.m[i][j] << " ";
		}
		std::cout << '\n';
	}
	
	return os;
}
