//
// Created by admin on 7/17/2017.
//

#ifndef DIPOLE_GENERATOR_CPP_GLOBALDATA_HPP
#define DIPOLE_GENERATOR_CPP_GLOBALDATA_HPP

#include <cmath>


enum SUPERCELL_TYPE { WIRE=1, FILM, DOT, BULK };

const int ERROR = -1;


/** Constant Matrix Values to be used for compile-time computation */

constexpr int M0008[3][3] = { { 8,  0,  0 },
                              { 0,  8,  0 },
                              { 0,  0,  8 } };

constexpr int M0016[3][3] = { {16,  0,  0 },
                              { 0, 16,  0 },
                              { 0,  0, 16 } };

constexpr int M0024[3][3] = { {24,  0,  0 },
                              { 0, 24,  0 },
                              { 0,  0, 24 } };

constexpr int M0048[3][3] = { {48,  0,  0 },
                              { 0, 48,  0 },
                              { 0,  0, 48 } };

constexpr int M0096[3][3] = { {96,  0,  0 },
                              { 0, 96,  0 },
                              { 0,  0, 96 } };

constexpr int M0192[3][3] = { {192,  0,  0 },
                              { 0, 192,  0 },
                              { 0,  0, 192 } };

constexpr int M0768[3][3] = { {768,  0,  0 },
                              { 0, 768,  0 },
                              { 0,  0, 768 } };

// TODO: The cell volume is successfully calculated at compile-time but now I need to restructure this to make it dependent on the input of N.
//       [Jose Fernando Lopez Fernandez - 07/17/17 03:44:38]

template <int N>
struct SUPERCELL_VOLUME {
    static_assert(N > 0);

    constexpr static int calculate_volume(const int a[3][3])
    {
        return (((a[1][0] * a[2][1]) - (a[2][0] * a[1][1])) * a[0][2] +
                ((a[2][0] * a[0][1]) - (a[0][0] * a[2][1])) * a[1][2] +
                ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1])) * a[2][2]);
    }
};


/** Generate constant values at compile time */

template <int N>
struct ABS {
    static_assert(N != INT_MIN);
    static constexpr int value = (N < 0) ? -N : N;
};

template <int N>
struct PI {
    static_assert(N >= 0);

    constexpr static auto value  = N * 4.00 * atan(1.00);
};

template <int N>
struct TOL {
    constexpr static auto value = N * 0.0000000000012;
};

template <int N>
struct ETA {
    constexpr static auto value = N * sqrt(-(log(TOL<1>::value)));
};

template <int N>
struct GCUT {
    constexpr static auto value = N * 2.0 * pow(ETA<1>::value, 2);
};

template <int N>
struct GCUT_SQ {
    constexpr static auto value = N * pow(GCUT<1>::value, 2);
};

template <int N>
struct ETA4 {
    constexpr static auto value = N * (1.0 / pow(ETA<1>::value, 2));
};


namespace DEBUG {
    void printConstants();
}

// Add these constants:
// TODO: c [Jose Fernando Lopez Fernandez - 07/17/17 05:37:45]
// TODO: residue [Jose Fernando Lopez Fernandez - 07/17/17 05:37:51]

/** We can "cache" typical cell sizes for optimization
 *  [Jose Fernando Lopez Fernandez - 07/17/17 03:02:24]
 */

#endif //DIPOLE_GENERATOR_CPP_GLOBALDATA_HPP
