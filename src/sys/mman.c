/*
 * Copyright 2022-2022 D'Arcy Smith.
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

#include "dc_posix/sys/dc_mman.h"

int dc_mlock(const struct dc_posix_env *env, struct dc_error *err, const void *addr, size_t len)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = mlock(addr, len);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mlockall(const struct dc_posix_env *env, struct dc_error *err, int flags)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = mlockall(flags);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void *dc_mmap(const struct dc_posix_env *env,
              struct dc_error           *err,
              void                      *addr,
              size_t                     len,
              int                        prot,
              int                        flags,
              int                        fildes,
              off_t                      off)
{
    void *ret_val;

    DC_TRACE(env);
    ret_val = mmap(addr, len, prot, flags, fildes, off);

    if(ret_val == MAP_FAILED)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mprotect(const struct dc_posix_env *env, struct dc_error *err, void *addr, size_t len, int prot)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = mprotect(addr, len, prot);

    if(ret_val == 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_msync(const struct dc_posix_env *env, struct dc_error *err, void *addr, size_t len, int flags)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = msync(addr, len, flags);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_munlock(const struct dc_posix_env *env, struct dc_error *err, const void *addr, size_t len)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = munlock(addr, len);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_munlockall(const struct dc_posix_env *env, struct dc_error *err)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = munlockall();

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_munmap(const struct dc_posix_env *env, struct dc_error *err, void *addr, size_t len)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = munmap(addr, len);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_posix_madvise(const struct dc_posix_env *env, struct dc_error *err, void *addr, size_t len, int advice)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = posix_madvise(addr, len, advice);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_shm_open(const struct dc_posix_env *env, struct dc_error *err, const char *name, int oflag, mode_t mode)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = shm_open(name, oflag, mode);

    if(ret_val < 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_shm_unlink(const struct dc_posix_env *env, struct dc_error *err, const char *name)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = shm_unlink(name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
