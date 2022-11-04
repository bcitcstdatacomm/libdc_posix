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


#include "dc_posix/dc_dlfcn.h"


int dc_dlclose(const struct dc_env *env, struct dc_error *err, void *handle)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dlclose(handle);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}

char *dc_dlerror(const struct dc_env *env)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dlerror();

    return ret_val;
}

void *dc_dlopen(const struct dc_env *env, struct dc_error *err, const char *file, int mode)
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dlopen(file, mode);

    if(ret_val == NULL)
    {
        // TODO: what?
    }

    return ret_val;
}

void *dc_dlsym(const struct dc_env *env, void *restrict handle, const char *restrict name)
{
    void *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = dlsym(handle, name);

    return ret_val;
}
