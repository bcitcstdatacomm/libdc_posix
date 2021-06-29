#ifndef LIBDC_POSIX_STDLIB_H
#define LIBDC_POSIX_STDLIB_H


#include "posix_env.h"
#include <sys/types.h>


void *dc_malloc(const struct dc_posix_env *env, int *err, size_t size);
void dc_free(const struct dc_posix_env *env, void *ptr);


#endif // LIBDC_POSIX_STDLIB_H
