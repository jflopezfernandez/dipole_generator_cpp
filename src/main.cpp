
/** Dipole-Generator Implementation in C++
 *  Author: Jose Lopez
 *  Date: 15-July-2017
 *
 */

#include "Main.hpp"
#include "Template-Input_Validation.hpp"

// Thread experiment [Jose Fernando Lopez Fernandez - 07/17/17 13:50:42]
void increaseZ(std::ofstream& output, int& n);

std::mutex m;


// Supercell Generation Functions
void generate_wire_supercell();
void generate_film_supercell();
void generate_dot_supercell();
void generate_bulk_supercell(const SupercellConfiguration& config);


int main()
{
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


    /** Generate configuration class */
    SupercellConfiguration configuration(n1, n2, nz, supercelltype);

    std::cout << "Supercell type: ";

    // TODO: Refactor for simplicity
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
            generate_bulk_supercell(configuration);
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


// TODO: Implement Generate Wire Supercell Generator Function
void generate_wire_supercell()
{
    std::cout << "[GENERATING WIRE SUPERCELL...]\n";
}

// TODO: Implement Film Supercell Generator Function
void generate_film_supercell()
{
    std::cout << "[GENERATING FILM SUPERCELL...]\n";
}

// TODO: Implement Dot Supercell Generator Function
void generate_dot_supercell()
{
    std::cout << "[GENERATING DOT SUPERCELL...]\n";
}

// TODO: Implement Bulk Supercell Generator Function
void generate_bulk_supercell(const SupercellConfiguration& config)
{
    std::cout << "[GENERATING BULK SUPERCELL...]\n";
    config.print();

    // ----- ----- BEGIN SUPERCELL GENERATION ----- -----

    std::cout << "Generating Ewald Matrix3D...\n";
    // TODO: Generate Ewald Matrix3D [Jose Fernando Lopez Fernandez - 07/17/17 05:34:26]

    // TODO: Display supercell volume here [Jose Fernando Lopez Fernandez - 07/17/17 05:35:36]


    // TODO: Estimate Number of Reciprocal Lattice Vectors to use [Jose Fernando Lopez Fernandez - 07/17/17 05:35:54]

    // TODO: Begin the matrix calculation [Jose Fernando Lopez Fernandez - 07/17/17 05:36:08]

    Matrix3D m(config.getN1(), config.getN2(), config.getNZ());
    std::cout << m << '\n';

    auto r = generate_reciprocal_lattice_vectors(m);
    std::cout << "Reciprocal Lattice Vectors: \n";
    std::cout << r << '\n';

    std::ofstream output1, output2, output3, output4;
    output1.open("test1.dat");
    output2.open("test2.dat");
    output3.open("test3.dat");
    output4.open("test4.dat");

    auto z0 = 0,
         z1 = 0,
         z2 = 0,
         z3 = 0;

    auto t1 = std::thread(&increaseZ, std::ref(output1), std::ref(z0));
    auto t2 = std::thread(&increaseZ, std::ref(output2), std::ref(z1));
    auto t3 = std::thread(&increaseZ, std::ref(output3), std::ref(z2));
    auto t4 = std::thread(&increaseZ, std::ref(output4), std::ref(z3));

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    if (t3.joinable())
        t3.join();

    if (t4.joinable())
        t4.join();

    output1.close();
    output2.close();
    output3.close();
    output4.close();


    std::cout << "Simulation Cell Volume: " << SUPERCELL_VOLUME<768>::calculate_volume(M0768) << '\n';
}


void increaseZ(std::ofstream& output, int& n)
{
    while (n < 113246208) {
        if (n % 100 == 0)
            output << '\n' << ++n << ' ';
        else
            output << ++n << ' ';
    }
}

