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


#include "dc_posix/dc_stdlib.h"
#include "dc_posix/dc_string.h"
#include <errno.h>
#include <unistd.h>


int dc_getsubopt(const struct dc_env *env, struct dc_error *err, char **optionp, char * const *keylistp, char **valuep)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getsubopt(optionp, keylistp, valuep);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_mkdtemp(const struct dc_env *env, struct dc_error *err, char *template)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = mkdtemp(template);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mkstemp(const struct dc_env *env, struct dc_error *err, char *template)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = mkstemp(template);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setenv(const struct dc_env *env, struct dc_error *err, const char *envname, const char *envval, int overwrite)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = setenv(envname, envval, overwrite);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_unsetenv(const struct dc_env *env, struct dc_error *err, const char *name)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = unsetenv(name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
