#ifndef __ASSERTION
#define __ASSERTION

#include <stdio.h>

#define assert(expr) { \
    if (!expr) { \
        fprintf(stderr, "%s:%d: Assertion `%s` failed.\n", __FILE__, __LINE__, __STRING(expr)); \
    } \
}

#endif
