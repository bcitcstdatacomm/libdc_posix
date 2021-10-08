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

#include "net/dc_if.h"


void dc_if_freenameindex(const struct dc_posix_env *env, struct if_nameindex *ptr)
{
    DC_TRACE(env);
    if_freenameindex(ptr);
}

char *dc_if_indextoname(const struct dc_posix_env *env, struct dc_error *err, unsigned int ifindex, char *ifname)
{
    char *name;

    DC_TRACE(env);
    errno = 0;
    name = if_indextoname(ifindex, ifname);

    if(name == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return name;
}

struct if_nameindex *dc_if_nameindex(const struct dc_posix_env *env, struct dc_error *err)
{
    struct if_nameindex *indexes;

    DC_TRACE(env);
    errno = 0;
    indexes = if_nameindex();

    if(indexes == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return indexes;
}

unsigned int dc_if_nametoindex(const struct dc_posix_env *env, const char *ifname)
{
    unsigned int index;

    DC_TRACE(env);
    errno = 0;
    index = if_nametoindex(ifname);

    return index;
}
