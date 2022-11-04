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


#include "dc_posix/dc_netdb.h"


void dc_endhostent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    endhostent();
}

void dc_endnetent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    endnetent();
}

void dc_endprotoent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    endprotoent();
}

void dc_endservent(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    endservent();
}

void dc_freeaddrinfo(const struct dc_env *env, struct addrinfo *ai)
{
    DC_TRACE(env);
    errno = 0;
    freeaddrinfo(ai);
}

const char *dc_gai_strerror(const struct dc_env *env, int ecode)
{
    const char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = gai_strerror(ecode);

    return ret_val;
}

int dc_getaddrinfo(const struct dc_env *env, struct dc_error *err, const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getaddrinfo(nodename, servname, hints, res);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}

struct hostent *dc_gethostent(const struct dc_env *env)
{
    struct hostent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = gethostent();

    return ret_val;
}

int dc_getnameinfo(const struct dc_env *env, struct dc_error *err, const struct sockaddr *restrict sa, socklen_t salen, char *restrict node, socklen_t nodelen, char *restrict service, socklen_t servicelen, int flags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getnameinfo(sa, salen, node, nodelen, service, servicelen, flags);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}

struct netent *dc_getnetbyaddr(const struct dc_env *env, uint32_t net, int type)
{
    struct netent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getnetbyaddr(net, type);

    return ret_val;
}

struct netent *dc_getnetbyname(const struct dc_env *env, const char *name)
{
    struct netent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getnetbyname(name);

    return ret_val;
}

struct netent *dc_getnetent(const struct dc_env *env)
{
    struct netent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getnetent();

    return ret_val;
}

struct protoent *dc_getprotobyname(const struct dc_env *env, const char *name)
{
    struct protoent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getprotobyname(name);

    return ret_val;
}

struct protoent *dc_getprotobynumber(const struct dc_env *env, int proto)
{
    struct protoent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getprotobynumber(proto);

    return ret_val;
}

struct protoent *dc_getprotoent(const struct dc_env *env, struct dc_error *err)
{
    struct protoent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getprotoent();

    return ret_val;
}

struct servent *dc_getservbyname(const struct dc_env *env, const char *name, const char *proto)
{
    struct servent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getservbyname(name, proto);

    return ret_val;
}

struct servent *dc_getservbyport(const struct dc_env *env, int port, const char *proto)
{
    struct servent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getservbyport(port, proto);

    return ret_val;
}

struct servent *dc_getservent(const struct dc_env *env)
{
    struct servent *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getservent();

    return ret_val;
}

void dc_sethostent(const struct dc_env *env, int stayopen)
{
    DC_TRACE(env);
    errno = 0;
    sethostent(stayopen);
}

void dc_setnetent(const struct dc_env *env, int stayopen)
{
    DC_TRACE(env);
    errno = 0;
    setnetent(stayopen);
}

void dc_setprotoent(const struct dc_env *env, int stayopen)
{
    DC_TRACE(env);
    errno = 0;
    setprotoent(stayopen);
}

void dc_setservent(const struct dc_env *env, int stayopen)
{
    DC_TRACE(env);
    errno = 0;
    setservent(stayopen);
}
