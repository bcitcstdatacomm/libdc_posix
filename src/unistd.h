#ifndef LIBDC_POSIX_UNISTD_H
#define LIBDC_POSIX_UNISTD_H


#include "posix_env.h"
#include <unistd.h>


ssize_t dc_read(const struct dc_posix_env *env, int *err, int fildes, void *buf, size_t nbyte);


#endif // LIBDC_POSIX_UNISTD_H
