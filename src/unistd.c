//
// Created by D’Arcy Smith on 2021-06-28.
//

#include "unistd.h"


ssize_t dc_read(const struct dc_posix_env *env, int *err, int fildes, void *buf, size_t nbyte)
{
    ssize_t ret_val;

    DC_TRACE(env);

    errno = 0;
    ret_val = read(fildes, buf, nbyte);

    if(ret_val == -1)
    {
        DC_REPORT_ERROR(env, errno);
        *err = errno;
    }

    return ret_val;
}
