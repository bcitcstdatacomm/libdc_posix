#ifndef LIBDC_POSIX_WORDEXP_H
#define LIBDC_POSIX_WORDEXP_H


#include "posix_env.h"
#include <wordexp.h>


int dc_wordexp(const struct dc_posix_env *env,
               int *err,
               const char *restrict words,
               wordexp_t *restrict pwordexp,
               int flags);


#endif // LIBDC_POSIX_WORDEXP_H
