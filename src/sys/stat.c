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

#include "sys/dc_stat.h"

int dc_chmod(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = chmod(path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fchmod(const struct dc_posix_env *env, struct dc_error *err, int fildes, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fchmod(fildes, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fchmodat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, mode_t mode, int flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fchmodat(fd, path, mode, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fstat(const struct dc_posix_env *env, struct dc_error *err, int fildes, struct stat *buf)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fstat(fildes, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fstatat(const struct dc_posix_env *env,
               struct dc_error           *err,
               int                        fd,
               const char * restrict path,
               struct stat * restrict buf,
               int flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fstatat(fd, path, buf, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_futimens(const struct dc_posix_env *env, struct dc_error *err, int fd, const struct timespec times[2])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = futimens(fd, times);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_lstat(const struct dc_posix_env *env,
             struct dc_error           *err,
             const char * restrict path,
             struct stat * restrict buf)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lstat(path, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mkdir(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mkdir(path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mkdirat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mkdirat(fd, path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mkfifo(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mkfifo(path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
int dc_mkfifoat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mkfifoat(fd, path, mode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

int dc_mknod(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode, dev_t dev)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mknod(path, mode, dev);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
int dc_mknodat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, mode_t mode, dev_t dev)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mknodat(fd, path, mode, dev);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

int dc_stat(const struct dc_posix_env *env,
            struct dc_error           *err,
            const char * restrict path,
            struct stat * restrict buf)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = stat(path, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

mode_t dc_umask(const struct dc_posix_env *env, mode_t cmask)
{
    mode_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = umask(cmask);

    return ret_val;
}

int dc_utimes(const struct dc_posix_env *env, struct dc_error *err, const char *path, const struct timeval times[2])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = utimes(path, times);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
