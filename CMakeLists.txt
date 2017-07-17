cmake_minimum_required(VERSION 3.7)
project(dipole_generator_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Main.hpp Timer.cpp Timer.hpp Template-Input_Validation.hpp)
add_executable(dipole_generator_cpp ${SOURCE_FILES} Main.hpp Timer.cpp Timer.hpp Template-Input_Validation.hpp)