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

#include "dc_stdlib.h"
#include "dc_string.h"
#include <errno.h>
#include <stdlib.h>

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/calloc.html
void *dc_calloc(const struct dc_posix_env *env, struct dc_error *err, size_t nelem, size_t elsize)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = calloc(nelem, elsize);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

_Noreturn void dc_exit(const struct dc_posix_env *env, int status)
{
    DC_TRACE(env);

    exit(status);
}

void dc_free(const struct dc_posix_env *env, void *ptr, size_t size)
{
    DC_TRACE(env);

    if(env->zero_free)
    {
        dc_memset(env, ptr, 0, size);
    }

    free(ptr);
}

char *dc_getenv(const struct dc_posix_env *env, const char *name)
{
    char *ret_val;

    DC_TRACE(env);
    errno  = 0;
    ret_val = getenv(name);

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/malloc.html
void *dc_malloc(const struct dc_posix_env *env, struct dc_error *err, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = malloc(size);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

void *dc_realloc(const struct dc_posix_env *env, struct dc_error *err, void *ptr, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = realloc(ptr, size);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

char *dc_realpath(const struct dc_posix_env *env, struct dc_error *err, const char *restrict file_name, char *restrict resolved_name)
{
    char *ret_val;

    DC_TRACE(env);
    errno  = 0;
    ret_val = realpath(file_name, resolved_name);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putenv(const struct dc_posix_env *env, struct dc_error *err, char *string)
{
    int ret_val;

    DC_TRACE(env);
    errno  = 0;
    ret_val = putenv(string);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setenv(const struct dc_posix_env *env, struct dc_error *err, const char *envname, const char *envval, int overwrite)
{
    int ret_val;

    DC_TRACE(env);
    errno  = 0;
    ret_val = setenv(envname, envval, overwrite);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
