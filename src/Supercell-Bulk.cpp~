
#include "Main.hpp"
#include <cstdint>
#include "Template-Constants.hpp"
#include <initializer_list>

// NOTE: Vars in capital letters I suspect can be turned into constants

STATUS Bulk(int d)
{
	std::cout.precision(MAX_PRECISION);
	
	std::cout << "PI: " << PI << '\n';
	std::cout << "2PI: " << PI*2 << '\n';
	std::cout << "TOL: " << TOL << '\n';
	std::cout << "ETA: " << ETA << '\n';
	std::cout << "ETA4: " << ETA4 << '\n';
	std::cout << "GCUT: " << GCUT << '\n';
	std::cout << "GCUT2: " << GCUT2 << '\n';

	
	double gx,
		   gy,
		   gz, 
		   g2, 
		   g2xy, 
		   argxy;
		   
	double gcut,
		   gcut2,
		   dum0;

	auto count = 0; // Sites constructed ( --> dxdxd)
	
	Vector am;
	
	Matrix a(d);
	Matrix b;
	
	CalculateReciprocalLatticeVectors(a.m, b.m);

	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			am.v[i] = am.v[i] + POW2(a.m[j][i]);
			//std::cout << am << '\n';
		}
		am.v[i] = sqrt(am.v[i]);
		//std::cout << am << '\n';
	}
	
	const auto CELL_VOL = POW3(d);
	const auto C = (PI8 / CELL_VOL);
	
	// TODO: Some caching/memoization can be done here
	int mg1 = static_cast<int>((GCUT * am.v[0]) / (PI * 2) + 1),
		mg2 = static_cast<int>((GCUT * am.v[1]) / (PI * 2) + 1),
		mg3 = static_cast<int>((GCUT * am.v[2]) / (PI * 2) + 1);
	
	std::cout.precision(MAX_PRECISION);
	std::cout << "GCUT: " << GCUT << '\n';
	
	std::cout << "mg1: " << mg1 << '\n';
	std::cout << "mg2: " << mg2 << '\n';
	std::cout << "mg3: " << mg3 << '\n';
	std::cout << "tol: " << TOL << '\n';
	
	std::ofstream output;
	output.open("DIP3D", std::ios::out | std::ios::binary);
	
	// The tons of variables declared in the file
	int ig1 = 0,
		ig2 = 0,
		ig3 = 0,
		iz  = 0,
		rx  = 0,
		ry  = 0,
		rz  = 0,
		ixy = 0;
	
	typedef uint16_t FLAG;
	
	#define NOT(x) -(x)
	#define IS_BETWEEN(x,y) ((x >= NOT(y))) && (x <= y))
	
	#define ON  0x0001
	#define OFF 0x0000
	
	#define AND(x,y) ((x && y) ? TRUE : FALSE)
	#define OR(x,y)  ((x || y) ? TRUE : FALSE)
	
	#define CHECK_FOR_ORIGIN(x,y,z) (((x == 0) && (y == 0) && (z == 0)) ? true : false)
	
	// This is a premature optimization
	//FLAG CheckForOrigin_x = ON;
	//FLAG CheckForOrigin_y = ON;
	//FLAG CheckForOrigin_z = ON;
	
	
	// Begin traversing the Matrix
	// NOTE: p-->[RHO]
	// 		 It's a density matrix dP[i,j]
	
	// The array is too large to fit on the stack frame, so I'm going to have to allocate it on the heap 
	double **dpij = new double*[6];
	for (auto i = 0; i < 6; ++i) {
		dpij[i] = new double[POW3(d)];
	}
	
	double fact = 0;
	
	for (auto i = 0u; i < d; i++) { 				// z-iterator
		for (auto j = 0u; j < d; j++) { 			// y-iterator
			for (auto k = 0u; k < d; k++) { 		// x-iterator
				// Logging to STDOUT for now
				std::cout << "Sites: " << ++count << '\n';
				
				double dum[6] = { 0 };
				
				if (ig1 < mg1) {
					if ((ig2 >= NOT(mg2)) && (ig2 <= (mg2))) {
						gx = (ig1 * b.m[0][0]) + (ig2 * b.m[0][1]);
						gy = (ig1 * b.m[1][0]) + (ig2 * b.m[1][1]);
						
						g2xy = POW2(gx) + POW2(gy);
						
						argxy = (gx * k) + (gy * j);
						
						if ((ig3 >= NOT(mg3)) && (ig3 <= (mg3))) {
							gz = ig3 * b.m[2][2];
							g2 = g2xy + POW2(gz);
							
							if ((g2 < GCUT2) && (g2 > 0.00000008)) {
								fact = 1.0;
								
								if (ig1 == 0)
									fact = 0.5;
								
								dum0 = fact * cos(argxy + gz * i) * exp(NOT(g2) * ETA4) / g2;
								
								dum[0] = dum[0] + dum0 * POW2(gx); dpij[0][count] * C;
								dum[1] = dum[1] + dum0 * POW2(gy); dpij[1][count] * C;
								dum[2] = dum[2] + dum0 * POW2(gz); dpij[2][count] * C;
								dum[3] = dum[3] + dum0 * gz * gy;  dpij[3][count] * C;
								dum[4] = dum[4] + dum0 * gx * gz;  dpij[4][count] * C;
								dum[5] = dum[5] + dum0 * gx * gy;  dpij[5][count] * C;
							}
						}
					}
				}
				
				if (CHECK_FOR_ORIGIN(i,j,k)) {
					dpij[0][count] = dpij[0][count] - RES;
					dpij[1][count] = dpij[1][count] - RES;
					dpij[2][count] = dpij[2][count] - RES;
				}
			} // END X-ITERATOR : FOR
			std::cout << '\n';
		} // END Y-ITERATOR : FOR
		std::cout << '\n';
	} // END Z-ITERATOR : FOR
	
	for (auto i = 0; i < 6; i++) {
		for (auto j = 0; j < POW3(d); j++) {
			output.write((char *) &(dpij[i][j]), sizeof (double));
			output << dpij[i][j] << '\n';
		}
	}
	
	output.close();
	
	// Clean up dynamically allocated array
	for (auto i = 0; i < 6; ++i) {
		delete [] dpij[i];
	}
	
	delete [] dpij;
	
	return UNDER_CONSTRUCTION;
}
