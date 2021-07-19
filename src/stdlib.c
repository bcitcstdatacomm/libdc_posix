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
    else
    {
        dc_error_reset(err);
    }

    return memory;
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
    else
    {
        dc_error_reset(err);
    }

    return memory;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/free.html
void dc_free(const struct dc_posix_env *env, void *ptr, size_t size)
{
    DC_TRACE(env);

    if(env->zero_free)
    {
        dc_memset(env, ptr, 0, size);
    }

    free(ptr);
}
