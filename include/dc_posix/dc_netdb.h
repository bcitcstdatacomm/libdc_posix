#ifndef LIBDC_POSIX_DC_NETDB_H
#define LIBDC_POSIX_DC_NETDB_H


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


#include "dc_posix_env.h"
#include <netdb.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 */
void dc_endhostent(const struct dc_posix_env *env);

/**
 *
 * @param env
 */
void dc_endnetent(const struct dc_posix_env *env);

/**
 *
 * @param env
 */
void dc_endprotoent(const struct dc_posix_env *env);

/**
 *
 * @param env
 */
void dc_endservent(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param ai
 */
void dc_freeaddrinfo(const struct dc_posix_env *env, struct addrinfo *ai);

/**
 *
 * @param env
 * @param ecode
 * @return
 */
const char *dc_gai_strerror(const struct dc_posix_env *env, int ecode);

/**
 *
 * @param env
 * @param err
 * @param nodename
 * @param servname
 * @param hints
 * @param res
 * @return
 */
int dc_getaddrinfo(const struct dc_posix_env *env, struct dc_error *err,
                   const char *restrict nodename, const char *restrict servname,
                   const struct addrinfo *restrict hints,
                   struct addrinfo **restrict res);

/**
 *
 * @param env
 * @return
 */
struct hostent *dc_gethostent(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param sa
 * @param salen
 * @param node
 * @param nodelen
 * @param service
 * @param servicelen
 * @param flags
 * @return
 */
int dc_getnameinfo(const struct dc_posix_env *env, struct dc_error *err,
                const struct sockaddr *restrict sa, socklen_t salen,
                char *restrict node, socklen_t nodelen, char *restrict service,
                socklen_t servicelen, int flags);

/**
 *
 * @param env
 * @param net
 * @param type
 * @return
 */
struct netent *dc_getnetbyaddr(const struct dc_posix_env *env, uint32_t net, int type);

/**
 *
 * @param env
 * @param name
 * @return
 */
struct netent *dc_getnetbyname(const struct dc_posix_env *env, const char *name);

/**
 *
 * @param env
 * @return
 */
struct netent *dc_getnetent(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param name
 * @return
 */
struct protoent *dc_getprotobyname(const struct dc_posix_env *env, const char *name);

/**
 *
 * @param env
 * @param proto
 * @return
 */
struct protoent *dc_getprotobynumber(const struct dc_posix_env *env, int proto);

/**
 *
 * @param env
 * @return
 */
struct protoent *dc_getprotoent(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param name
 * @param proto
 * @return
 */
struct servent *dc_getservbyname(const struct dc_posix_env *env, const char *name, const char *proto);

/**
 *
 * @param env
 * @param port
 * @param proto
 * @return
 */
struct servent *dc_getservbyport(const struct dc_posix_env *env, int port, const char *proto);

/**
 *
 * @param env
 * @return
 */
struct servent *dc_getservent(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param stayopen
 */
void dc_sethostent(const struct dc_posix_env *env, int stayopen);

/**
 *
 * @param env
 * @param stayopen
 */
void dc_setnetent(const struct dc_posix_env *env, int stayopen);

/**
 *
 * @param env
 * @param stayopen
 */
void dc_setprotoent(const struct dc_posix_env *env, int stayopen);

/**
 *
 * @param env
 * @param stayopen
 */
void dc_setservent(const struct dc_posix_env *env, int stayopen);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_NETDB_H
