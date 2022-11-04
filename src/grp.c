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


#include "dc_posix/dc_grp.h"


struct group *dc_getgrgid(const struct dc_env *env, struct dc_error *err, gid_t gid)
{
    struct group *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getgrgid(gid);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getgrgid_r(const struct dc_env *env, struct dc_error *err, gid_t gid, struct group *grp, char *buffer, size_t bufsize, struct group **result)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getgrgid_r(gid, grp, buffer, bufsize, result);

    if(ret_val == -1)
    {
        // TODO: what?
    }

    return ret_val;
}

struct group *dc_getgrnam(const struct dc_env *env, struct dc_error *err, const char *name)
{
    struct group *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getgrnam(name);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getgrnam_r(const struct dc_env *env, struct dc_error *err, const char *name, struct group *grp, char *buffer, size_t bufsize, struct group **result)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getgrnam_r(name, grp, buffer, bufsize, result);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}
