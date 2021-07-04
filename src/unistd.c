/*
 * Copyright 2021-2021 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "unistd.h"
#include <unistd.h>


// https://pubs.opengroup.org/onlinepubs/9699919799/
ssize_t dc_read(const struct dc_posix_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = read(fildes, buf, nbyte);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }
    else
    {
        dc_error_reset(err);
    }

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/write.html
ssize_t dc_write(const struct dc_posix_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = write(fildes, buf, nbyte);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }
    else
    {
        dc_error_reset(err);
    }

    return ret_val;
}
