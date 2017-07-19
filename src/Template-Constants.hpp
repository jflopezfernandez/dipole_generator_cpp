#ifndef T_CONSTANTS
#define T_CONSTANTS

#include <limits>
#include <float.h>

// IEEE-754 Double-precision floating-point compliance, with at least:
// 		  Sign:        (1)  bit
// 		  Exponent:    (11) bits
// 		  Significand: (53) bits

// Computed exactly with Mathematica
// NOTE: May need to change to long double in the future

const double PI    =     3.1415926535897932; 		// 4 * ATAN(1.0)
const double TOL   =     0.0000000000010000; 		// 1e-12
const double ETA   =     5.2535217694569319; 		// SQRT(-LOG(TOL))
const double ETA4  =     0.0090478017063177; 		// 1 / (4 * POW2(ETA))
const double GCUT  =    55.2620422318570964; 		// 2 * POW2(ETA)
const double GCUT2 =  3053.8933116355572540; 	    // POW2(GCUT)

const double PI8   =  25.132741228718345907;
const double RES   = 109.259498400862211654;


constexpr auto MAX_PRECISION = std::numeric_limits<long double>::digits10+1;

#endif // T_CONSTANTS
