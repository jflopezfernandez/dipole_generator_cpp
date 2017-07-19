
#include "Main.hpp"
#include "Template-Constants.hpp"

// NOTE: Vars in capital letters I suspect can be turned into constants

STATUS Bulk(int d)
{
	//std::cout.precision(MAX_PRECISION);
	//
	//std::cout << "PI: " << PI << '\n';
	//std::cout << "2PI: " << PI*2 << '\n';
	//std::cout << "TOL: " << TOL << '\n';
	//std::cout << "ETA: " << ETA << '\n';
	//std::cout << "ETA4: " << ETA4 << '\n';
	//std::cout << "GCUT: " << GCUT << '\n';
	//std::cout << "GCUT2: " << GCUT2 << '\n';
	
	// NOTE: Changing data structures from real->int until it's apparent
	// 		 that the extra precision is needed.
	
	// ERROR: Causing segmentation fault
	//int dpig[6][POW3(d)];
	
	double gx,
		   gy,
		   gz, 
		   g2, 
		   g2xy, 
		   argxy;
		   
	double gcut,
		   gcut2,
		   dum0;
		   
	double C;

	auto count = 0; // Sites constructed ( --> dxdxd)
	
	Vector am;
	std::cout << "am - " << am << '\n';
	
	Matrix a(d);
	Matrix b;
	
	// This just goes to dxdxd, can we get rid of this?
	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			am.v[i] = am.v[i] + POW2(a.m[j][i]);
			//std::cout << am << '\n';
		}
		am.v[i] = sqrt(am.v[i]);
		//std::cout << am << '\n';
	}
	
	const auto cellvol = POW3(d);
	std::cout << "Cell volume: " << cellvol << " \n";
	
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
	output.open("TEST.DAT");
	
	// The tons of variables declared in the file
	int ig1,
		ig2,
		ig3,
		iz,
		rx,
		ry,
		rz,
		ixy;
	
	double dum0;
	
	// Begin traversing the Matrix
	for (auto i = 0u; i < d; i++) {
		for (auto j = 0u; j < d; j++) {
			for (auto k = 0u; k < d; k++) {
				// Logging to STDOUT for now
				std::cout << "Sites: " << ++count << '\n';
				
				//...
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	
	output.close();
	
	return UNDER_CONSTRUCTION;
}
