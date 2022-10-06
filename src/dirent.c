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

#include "dc_posix/dc_dirent.h"

int dc_alphasort(const struct dc_posix_env *env, const struct dirent **d1, const struct dirent **d2)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = alphasort(d1, d2);

    return ret_val;
}

int dc_closedir(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = closedir(dirp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_dirfd(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dirfd(dirp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

DIR *dc_fdopendir(const struct dc_posix_env *env, struct dc_error *err, int fd)
{
    DIR *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fdopendir(fd);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

DIR *dc_opendir(const struct dc_posix_env *env, struct dc_error *err, const char *dirname)
{
    DIR *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = opendir(dirname);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct dirent *dc_readdir(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp)
{
    struct dirent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = readdir(dirp);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_rewinddir(const struct dc_posix_env *env, DIR *dirp)
{
    DC_TRACE(env);
    errno = 0;
    rewinddir(dirp);
}

int dc_scandir(const struct dc_posix_env *env, struct dc_error *err, const char *dir, struct dirent ***namelist, int (*sel)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **))
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = scandir(dir, namelist, sel, compar);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_seekdir(const struct dc_posix_env *env, DIR *dirp, long loc)
{
    DC_TRACE(env);
    errno = 0;
    seekdir(dirp, loc);
}

long dc_telldir(const struct dc_posix_env *env, DIR *dirp)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = telldir(dirp);

    return ret_val;
}
