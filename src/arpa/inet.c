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


uint32_t dc_htonl(const struct dc_posix_env *env, uint32_t hostlong)
{
    uint32_t converted;

    DC_TRACE(env);
    errno = 0;
    converted = htonl(hostlong);

    return converted;
}


uint16_t dc_htons(const struct dc_posix_env *env, uint16_t hostshort)
{
    uint16_t converted;

    DC_TRACE(env);
    errno = 0;
    converted = htons(hostshort);

    return converted;
}


uint32_t dc_ntohl(const struct dc_posix_env *env, uint32_t netlong)
{
    uint32_t converted;

    DC_TRACE(env);
    errno = 0;
    converted = ntohl(netlong);

    return converted;
}


uint16_t dc_ntohs(const struct dc_posix_env *env, uint16_t netshort)
{
    uint32_t converted;

    DC_TRACE(env);
    errno = 0;
    converted = ntohs(netshort);

    return converted;
}


in_addr_t dc_inet_addr(const struct dc_posix_env *env, struct dc_error *err, const char *cp)
{
    in_addr_t addr;

    DC_TRACE(env);
    errno        = 0;
    addr = inet_addr(cp);

    if(addr == (in_addr_t) -1)
    {
        // TODO: the documentation is unclear on what happens if there is an error
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return addr;
}

char *dc_inet_ntoa(const struct dc_posix_env *env, struct in_addr in)
{
    char *addr;

    DC_TRACE(env);
    errno = 0;
    addr = inet_ntoa(in);

    return addr;
}

const char *dc_inet_ntop(const struct dc_posix_env *env,
                         struct dc_error           *err,
                         int                        af,
                         const void * restrict src,
                         char * restrict dst,
                         socklen_t size)
{
    const char *presentation;

    DC_TRACE(env);
    errno        = 0;
    presentation = inet_ntop(af, src, dst, size);

    if(presentation == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return presentation;
}

int dc_inet_pton(const struct dc_posix_env *env,
                 struct dc_error           *err,
                 int                        af,
                 const char * restrict src,
                 void * restrict dst)
{
    int numeric;

    DC_TRACE(env);
    errno   = 0;
    numeric = inet_pton(af, src, dst);

    if(numeric == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return numeric;
}
