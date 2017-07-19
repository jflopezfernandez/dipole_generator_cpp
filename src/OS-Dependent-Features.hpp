#ifndef OS_DEPENDENT_FEATURES_HPP
#define OS_DEPENDENT_FEATURES_HPP


#ifdef _WIN32
    #define CLEARSCREEN "cls"
#else
    #define CLEARSCREEN "clear"
#endif


#endif // OS_DEPENDENT_FEATURES_HPP
