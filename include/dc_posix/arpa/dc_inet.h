#ifndef LIBDC_POSIX_ARPA_DC_INET_H
#define LIBDC_POSIX_ARPA_DC_INET_H


/*
 * Copyright 2022-2022 D'Arcy Smith.
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
#include <arpa/inet.h>


#ifdef __cplusplus
extern "C" {
#endif


uint32_t dc_htonl(const struct dc_env *env, uint32_t hostlong);
uint16_t dc_htons(const struct dc_env *env, uint16_t hostshort);
uint32_t dc_ntohl(const struct dc_env *env, uint32_t netlong);
uint16_t dc_ntohs(const struct dc_env *env, uint16_t netshort);
in_addr_t dc_inet_addr(const struct dc_env *env, struct dc_error *err, const char *cp);
char *dc_inet_ntoa(const struct dc_env *env, struct in_addr in);
const char *dc_inet_ntop(const struct dc_env *env, struct dc_error *err, int af, const void *restrict src, char *restrict dst, socklen_t size);
int dc_inet_pton(const struct dc_env *env, struct dc_error *err, int af, const char *restrict src, void *restrict dst);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_ARPA_DC_INET_H
