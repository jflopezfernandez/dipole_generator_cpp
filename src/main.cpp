
///** Dipole-Generator Implementation in C++
// *  Author: Jose Lopez
// *  Date: 15-July-2017
// *
// */

#include "Main.hpp"
#include "Template-Input_Validation.hpp"


#define POW2(x) (x*x)
#define POW3(x) (x*x*x)


STATUS Dot (int d);
STATUS Wire(int d);
STATUS Film(int d);
STATUS Bulk(int d);


int main()
{
    system(CLEARSCREEN);
    
    const auto start = std::chrono::system_clock::now();

    std::cout << "Please enter supercell dimension: ";
    const auto supercelldimension = IO::get<int>();
    
    std::cout << "Dimensions: " << supercelldimension << "x" << supercelldimension << "x" << supercelldimension << '\n';
    std::cout << "Size: " << POW3(supercelldimension) << " \n\n";
    
    std::ofstream dipoleoutputfile;
    dipoleoutputfile.open("DIP3D", std::ofstream::out);
    
    STATUS (*GenerateSupercell)(int dimension);
    
    std::cout << "Please select the supercell type: \n";
    std::cout << "\t1. Dot \n";
    std::cout << "\t2. Wire \n";
    std::cout << "\t3. Film \n";
    std::cout << "\t4. Bulk \n";
    auto response = IO::get<int>();
    
    switch (response) {
    	case (DOT):
    		GenerateSupercell = Dot;
    		break;
    	case (WIRE):
    		GenerateSupercell = Wire;
    		break;
    	case (FILM):
    		GenerateSupercell = Film;
    		break;
    	case (BULK):
    		GenerateSupercell = Bulk;
    		break;
    	default:
    		std::cout << "[ERROR] Could not understand input... \n";
    		exit(ERROR);
    }
    
    GenerateSupercell(supercelldimension);
    
    
    // Program wind-down -> close buffers and stop timer
    dipoleoutputfile.close();
    const auto end = std::chrono::system_clock::now();
    
    std::cout << "Program running time: ";
    const auto diff = end - start;
    std::cout << std::chrono::duration<double, std::ratio<1,1000>>(diff).count() << "ms \n";
}


STATUS Dot(int d)
{
	std::cout << "generate dot sc \n";
	
	return SUCCESS;
}

STATUS Wire(int d)
{
	std::cout << "generate wire sc \n";
	
	return SUCCESS;
}

STATUS Film(int d)
{
	std::cout << "generate film sc \n";
	
	return SUCCESS;
}

STATUS Bulk(int d)
{
	std::cout << "generate bulk sc \n";
	
	return SUCCESS;
}


