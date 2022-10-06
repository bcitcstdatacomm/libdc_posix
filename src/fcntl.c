/*
 * Copyright 2021-2022 D'Arcy Smith.
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

#include "dc_posix/dc_fcntl.h"
#include <stdarg.h>

int dc_creat(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = creat(path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_open(const struct dc_posix_env *env, struct dc_error *err, const char *path, unsigned int oflag, ...)
{
    int ret_val;
    mode_t mode;

    DC_TRACE(env);
    errno   = 0;

    if(((oflag & DC_O_CREAT) != 0)
#ifdef O_TMPFILE
    || ((oflag & O_TMPFILE) != 0)
#endif
    )
    {
        va_list arg;

        va_start(arg, oflag);
        mode = va_arg(arg, mode_t);
        va_end(arg);
    }
    else
    {
        mode = 0;
    }

    ret_val = open(path, (int)oflag, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_openat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, unsigned int oflag, ...)
{
    int ret_val;
    mode_t mode;

    DC_TRACE(env);
    errno   = 0;

    if((((oflag) & DC_O_CREAT) != 0)
#ifdef O_TMPFILE
        || (((oflag) & O_TMPFILE) != 0)
#endif
    )
    {
        va_list arg;
        va_start(arg, oflag);
        mode = va_arg(arg, mode_t);
        va_end(arg);
    }
    else
    {
        mode = 0;
    }

    ret_val = openat(fd, path, (int)oflag, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
int dc_posix_fadvise(const struct dc_posix_env *env, struct dc_error *err, int fd, off_t offset, off_t len, int advice)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = posix_fadvise(fd, offset, len, advice);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_posix_fallocate(const struct dc_posix_env *env, struct dc_error *err, int fd, off_t offset, off_t len)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = posix_fallocate(fd, offset, len);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/
