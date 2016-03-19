#ifndef CUSTOM_STRING_EXCEPTION_H
#define CUSTOM_STRING_EXCEPTION_H

#include "stringf.h"

class exception : public std::string {
    public:
        template< typename... argv >
        exception( const char* format, argv... args ) {
            std::string::operator=(stringf(format, args...));
        };
        const char* what() const { return c_str(); };
};

#define create_exception(T) class T : public exception { public: using exception::exception; };

#endif

