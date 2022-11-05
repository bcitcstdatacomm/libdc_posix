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


#include "dc_posix/net/dc_if.h"


void dc_if_freenameindex(const struct dc_env *env, struct if_nameindex *ptr)
{
    DC_TRACE(env);
    errno = 0;
    if_freenameindex(ptr);
}

char *dc_if_indextoname(const struct dc_env *env, struct dc_error *err, unsigned ifindex, char *ifname)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = if_indextoname(ifindex, ifname);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct if_nameindex *dc_if_nameindex(const struct dc_env *env, struct dc_error *err)
{
    struct if_nameindex *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = if_nameindex();

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned dc_if_nametoindex(const struct dc_env *env, const char *ifname)
{
    unsigned ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = if_nametoindex(ifname);

    if(ret_val == 0)
    {
        // TODO: what?
    }

    return ret_val;
}
