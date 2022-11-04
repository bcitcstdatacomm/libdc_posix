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


#include "dc_posix/dc_pwd.h"


struct passwd *dc_getpwnam(const struct dc_env *env, struct dc_error *err, const char *name)
{
    struct passwd *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpwnam(name);

    if(ret_val == NULL && errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getpwnam_r(const struct dc_env *env, struct dc_error *err, const char *name, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpwnam_r(name, pwd, buffer, bufsize, result);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}

struct passwd *dc_getpwuid(const struct dc_env *env, struct dc_error *err, uid_t uid)
{
    struct passwd *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpwuid(uid);

    if(ret_val == NULL && errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getpwuid_r(const struct dc_env *env, struct dc_error *err, uid_t uid, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getpwuid_r(uid, pwd, buffer, bufsize, result);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}
