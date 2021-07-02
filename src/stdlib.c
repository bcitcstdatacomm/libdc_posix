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


#include "stdlib.h"
#include <stdlib.h>
#include <errno.h>


void *dc_calloc(const struct dc_posix_env *env, int *err, size_t nelem, size_t elsize)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = calloc(nelem, elsize);
    *err   = errno;

    if(memory == NULL)
    {
        DC_REPORT_ERROR(env, errno);
    }

    return memory;
}

void *dc_malloc(const struct dc_posix_env *env, int *err, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno = 0;

    if(env->zero_malloc)
    {
        memory = calloc(1, size);
    }
    else
    {
        memory = malloc(size);
    }

    *err = errno;

    if(memory == NULL)
    {
        DC_REPORT_ERROR(env, errno);
    }

    return memory;
}

void dc_free(const struct dc_posix_env *env, void *ptr)
{
    DC_TRACE(env);
    free(ptr);
}
