#ifndef STRINGF_H
#define STRINGF_H

#include <string>

template< typename... argv >
std::string stringf( const char* format, argv... args ) {
    const size_t SIZE = std::snprintf( NULL, 0, format, args... );

    char buf[SIZE+1];
    std::snprintf( buf, SIZE+1, format, args... );
    return std::move(std::string(buf));
}

#endif

