/// Macros
/// me@andreivictor.net
/// Collection of macros

#ifndef ARL_MACROS_HPP
#define ARL_MACROS_HPP

#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))

#define SAFEDELETE(x) if((x) != nullptr) { \
    delete (x); \
    (x) = nullptr; }

#define SAFEDELETE_ARRAY(x) if((x) != nullptr) { \
    delete [] (x); \
    (x) = nullptr; }

#endif //ARL_MACROS_HPP