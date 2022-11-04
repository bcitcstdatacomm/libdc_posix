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


#include <dc_env/env.h>
#include <netdb.h>


#ifdef __cplusplus
extern "C" {
#endif


void dc_endhostent(const struct dc_env *env);
void dc_endnetent(const struct dc_env *env);
void dc_endprotoent(const struct dc_env *env);
void dc_endservent(const struct dc_env *env);
void dc_freeaddrinfo(const struct dc_env *env, struct addrinfo *ai);
const char *dc_gai_strerror(const struct dc_env *env, int ecode);
int dc_getaddrinfo(const struct dc_env *env, struct dc_error *err, const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);
struct hostent *dc_gethostent(const struct dc_env *env);
int dc_getnameinfo(const struct dc_env *env, struct dc_error *err, const struct sockaddr *restrict sa, socklen_t salen, char *restrict node, socklen_t nodelen, char *restrict service, socklen_t servicelen, int flags);
struct netent *dc_getnetbyaddr(const struct dc_env *env, uint32_t net, int type);
struct netent *dc_getnetbyname(const struct dc_env *env, const char *name);
struct netent *dc_getnetent(const struct dc_env *env);
struct protoent *dc_getprotobyname(const struct dc_env *env, const char *name);
struct protoent *dc_getprotobynumber(const struct dc_env *env, int proto);
struct protoent *dc_getprotoent(const struct dc_env *env, struct dc_error *err);
struct servent *dc_getservbyname(const struct dc_env *env, const char *name, const char *proto);
struct servent *dc_getservbyport(const struct dc_env *env, int port, const char *proto);
struct servent *dc_getservent(const struct dc_env *env);
void dc_sethostent(const struct dc_env *env, int stayopen);
void dc_setnetent(const struct dc_env *env, int stayopen);
void dc_setprotoent(const struct dc_env *env, int stayopen);
void dc_setservent(const struct dc_env *env, int stayopen);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_NETDB_H
