CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT(dipole_generator_cpp)

#ADD_COMPILE_OPTIONS(-std=c++17 -Wall -Wextra -Wpedantic -Werror -lquadmath)
ADD_COMPILE_OPTIONS(-std=gnu++11 -lquadmath)

#ADD_DEFINITIONS(QUADMATH_INCLUDE_DIR=C:\\mingw64\\mingw64-7.1.0\\lib\\gcc\\x86_64-w64-mingw32\\7.1.0)


#FIND_PACKAGE(quadmath REQUIRED)

#INCLUDE_DIRECTORIES(${QUADMATH_INCLUDE_DIR})

#TARGET_LINK_LIBRARIES(dipole_generator_cpp quadmath)

SET(SOURCE_FILES main.cpp Main.hpp Template-Input_Validation.hpp SupercellConfiguration.cpp SupercellConfiguration.hpp GlobalData.hpp BulkSupercellGenerator.cpp BulkSupercellGenerator.hpp GlobalData.cpp Matrix3D.cpp Matrix3D.hpp Point3D.cpp Point3D.hpp Vector3D.cpp Vector3D.hpp NumericTypes.cpp NumericTypes.hpp)
ADD_EXECUTABLE(dipole_generator_cpp ${SOURCE_FILES} Main.hpp Template-Input_Validation.hpp SupercellConfiguration.cpp SupercellConfiguration.hpp GlobalData.hpp BulkSupercellGenerator.cpp BulkSupercellGenerator.hpp GlobalData.cpp Matrix3D.cpp Matrix3D.hpp Vector3D.cpp Vector3D.hpp NumericTypes.cpp NumericTypes.hpp)