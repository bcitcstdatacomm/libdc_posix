#ifndef LIBDC_POSIX_INTTYPES_H
#define LIBDC_POSIX_INTTYPES_H


#include "posix_env.h"
#include <inttypes.h>


/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @param base
 * @return
 */
intmax_t dc_strtoimax(const struct dc_posix_env *env,
                      int *err,
                      const char *restrict nptr,
                      char **restrict endptr,
                      int base);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @param base
 * @return
 */
uintmax_t dc_strtoumax(const struct dc_posix_env *env,
                       int *err,
                       const char *restrict nptr,
                       char **restrict endptr,
                       int base);


#endif // LIBDC_POSIX_INTTYPES_H
