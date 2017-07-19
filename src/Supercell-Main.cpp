
#include "Main.hpp"


/** DISABLED: I'm just cubing the dimension, I'm not running these matrix operations
	int CELL_VOLUMEf(int a[3][3])
	{
		auto sum  = 0;
			 sum += ((a[1][0] * a[2][1]) - (a[2][0] * a[1][1])) * a[0][2];
			 sum += ((a[2][0] * a[0][1]) - (a[0][0] * a[2][1])) * a[1][2];
			 sum += ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1])) * a[2][2];
			 
		return sum;
	}
*/


void CalculateReciprocalLatticeVectors(double a[3][3], double b[3][3])
{
	b[0][0] = (a[1][1] * a[2][2]) - (a[2][1] * a[1][2]);
    b[1][0] = (a[2][1] * a[0][2]) - (a[0][1] * a[2][2]);
    b[2][0] = (a[0][1] * a[1][2]) - (a[1][1] * a[0][2]);
    b[0][1] = (a[1][2] * a[2][0]) - (a[2][2] * a[1][0]);
    b[1][1] = (a[2][2] * a[0][0]) - (a[0][2] * a[2][0]);
    b[2][1] = (a[0][2] * a[1][0]) - (a[1][2] * a[0][0]);
    b[0][2] = (a[1][0] * a[2][1]) - (a[2][0] * a[1][1]);
    b[1][2] = (a[2][0] * a[0][1]) - (a[0][0] * a[2][1]);
    b[2][2] = (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
    
    const auto c = (PI * 2);

	auto CI = 0.0;    
    for (auto i = 0; i < 3; i++) {
		CI = c / ((a[0][i] * b[0][i]) + (a[1][i] * b[1][i]) + (a[2][i] * b[2][i]));
		
		b[0][i] *= CI;
		b[1][i] *= CI;
		b[2][i] *= CI;
    }
}
