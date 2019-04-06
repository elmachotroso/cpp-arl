#ifndef ARL_macros_h
#define ARL_macros_h

#define SAFEDELETE(x) if((x) != nullptr) { \
    delete (x); \
    (x) = nullptr; }

#define SAFEDELETE_ARRAY(x) if((x) != nullptr) { \
    delete [] (x); \
    (x) = nullptr; }

#endif //ARL_macros_h