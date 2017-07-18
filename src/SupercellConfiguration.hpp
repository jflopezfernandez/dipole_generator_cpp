//
// Created by admin on 7/17/2017.
//

#ifndef DIPOLE_GENERATOR_CPP_SUPERCELLCONFIGURATION_HPP
#define DIPOLE_GENERATOR_CPP_SUPERCELLCONFIGURATION_HPP


class SupercellConfiguration {
private:
    /** Supercell Dimensions */
    unsigned int n1;
    unsigned int n2;
    unsigned int nz;

    enum SUPERCELL_TYPE type;

public:
    SupercellConfiguration() = delete;

    SupercellConfiguration(const int& x, const int& y, const int& z, const int& t);

    unsigned int getN1() const { return n1; }
    unsigned int getN2() const { return n2; }
    unsigned int getNZ() const { return nz; }

    void print() const;
};


#endif //DIPOLE_GENERATOR_CPP_SUPERCELLCONFIGURATION_HPP
