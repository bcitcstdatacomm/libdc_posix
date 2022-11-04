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


#include "dc_posix/arpa/dc_inet.h"


uint32_t dc_htonl(const struct dc_env *env, uint32_t hostlong)
{
    uint32_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = htonl(hostlong);

    return ret_val;
}

uint16_t dc_htons(const struct dc_env *env, uint16_t hostshort)
{
    uint16_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = htons(hostshort);

    return ret_val;
}

uint32_t dc_ntohl(const struct dc_env *env, uint32_t netlong)
{
    uint32_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ntohl(netlong);

    return ret_val;
}

uint16_t dc_ntohs(const struct dc_env *env, uint16_t netshort)
{
    uint16_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ntohs(netshort);

    return ret_val;
}

in_addr_t dc_inet_addr(const struct dc_env *env, struct dc_error *err, const char *cp)
{
    in_addr_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = inet_addr(cp);

    if(ret_val == (in_addr_t)-1)
    {
        // TODO: some sort of error
    }

    return ret_val;
}

char *dc_inet_ntoa(const struct dc_env *env, struct in_addr in)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = inet_ntoa(in);

    return ret_val;
}

const char *dc_inet_ntop(const struct dc_env *env, struct dc_error *err, int af, const void *restrict src, char *restrict dst, socklen_t size)
{
    const char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = inet_ntop(af, src, dst, size);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_inet_pton(const struct dc_env *env, struct dc_error *err, int af, const char *restrict src, void *restrict dst)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = inet_pton(af, src, dst);

    if(ret_val != 1)
    {
        if(ret_val == 0)
        {
            // TODO: what?
        }
        else
        {
            DC_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return ret_val;
}
