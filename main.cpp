
/** Dipole-Generator Implementation in C++
 *  Author: Jose Lopez
 *  Date: 15-July-2017
 *
 */

#include "Main.hpp"
#include "Template-Input_Validation.hpp"


// Supercell Generation Functions
void generate_wire_supercell();
void generate_film_supercell();
void generate_dot_supercell();
void generate_bulk_supercell();


int main() {

    enum SUPERCELL_TYPE { WIRE=1, FILM, DOT, BULK };

    system("CLS");

    std::cout << "Please enter the supercell dimensions: ";
    auto n1 = IO::get<int>();
    auto n2 = IO::get<int>();
    auto nz = IO::get<int>();

    auto program_start = std::chrono::system_clock::now();

    std::cout << "\nSupercell dimensions: \n";
    std::cout << "\tn1: " << n1 << '\n';
    std::cout << "\tn2: " << n2 << '\n';
    std::cout << "\tnz: " << nz << '\n';

    std::cout << "Please select supercell type: \n";
    std::cout << "\t1. Wire \n";
    std::cout << "\t2. Film \n";
    std::cout << "\t3. Dot \n";
    std::cout << "\t4. Bulk \n";
    auto supercelltype = IO::get<int>();

    std::cout << "Supercell type: ";

    switch (supercelltype) {
        case (WIRE):
            std::cout << "WIRE\n\n";
            generate_wire_supercell();
            break;
        case (FILM):
            std::cout << "FILM\n\n";
            generate_film_supercell();
            break;
        case (DOT):
            std::cout << "DOT\n\n";
            generate_dot_supercell();
            break;
        case (BULK):
            std::cout << "BULK\n\n";
            generate_bulk_supercell();
            break;
        default: {
            std::cout << "[ERROR] Unrecognized supercell type entered. \n";
        }
    }



    /** Get the elapsed time of the program */
    auto program_end = std::chrono::system_clock::now();
    auto elapsed_time = program_end - program_start;

    std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time);
    std::chrono::milliseconds m = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time);

    std::cout << "\n\n\tExecution Time: ";
    std::cout << s.count() << "s (";
    std::cout << m.count() << "ms) \n\n";
}


void generate_wire_supercell()
{
    std::cout << "[GENERATING WIRE SUPERCELL...]\n";
    std::cout << "test buil.d";
}

// DEBUG: testing...

void generate_film_supercell()
{
    std::cout << "[GENERATING FILM SUPERCELL...]\n";
}


void generate_dot_supercell()
{
    std::cout << "[GENERATING DOT SUPERCELL...]\n";
}


void generate_bulk_supercell()
{
    std::cout << "[GENERATING BULK SUPERCELL...]\n";
}

