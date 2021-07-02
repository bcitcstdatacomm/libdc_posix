#include "inttypes.h"
#include <errno.h>


intmax_t dc_strtoimax(const struct dc_posix_env *env,
                      int *err,
                      const char *restrict nptr,
                      char **restrict endptr,
                      int base)
{
    intmax_t  value;

    DC_TRACE(env);
    errno = 0;
    value = strtoimax(nptr, endptr, base);

    if(errno != 0)
    {
        *err = errno;
        DC_REPORT_ERROR(env, errno);
    }

    return value;
}

uintmax_t dc_strtoumax(const struct dc_posix_env *env,
                       int *err,
                       const char *restrict nptr,
                       char **restrict endptr,
                       int base)
{
    uintmax_t  value;

    DC_TRACE(env);
    errno = 0;
    value = strtoumax(nptr, endptr, base);
    *err  = errno;

    if(errno != 0)
    {
        DC_REPORT_ERROR(env, errno);
    }

    return value;
}

