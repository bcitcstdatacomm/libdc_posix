#ifndef LIBDC_POSIX_ARPA_INET_H
#define LIBDC_POSIX_ARPA_INET_H


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


#include "../dc_posix_env.h"
#include "../dc_posix_env.h"
#include <arpa/inet.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param hostlong
 * @return
 */
uint32_t dc_htonl(const struct dc_posix_env *env, uint32_t hostlong);

/**
 *
 * @param env
 * @param hostshort
 * @return
 */
uint16_t dc_htons(const struct dc_posix_env *env, uint16_t hostshort);

/**
 *
 * @param env
 * @param netlong
 * @return
 */
uint32_t dc_ntohl(const struct dc_posix_env *env, uint32_t netlong);

/**
 *
 * @param env
 * @param netshort
 * @return
 */
uint16_t dc_ntohs(const struct dc_posix_env *env, uint16_t netshort);

/**
 *
 * @param env
 * @param err
 * @param cp
 * @return
 */
in_addr_t dc_inet_addr(const struct dc_posix_env *env, struct dc_error *err, const char *cp);

/**
 *
 * @param env
 * @param in
 * @return
 */
char *dc_inet_ntoa(const struct dc_posix_env *env, struct in_addr in);

/**
 *
 * @param env
 * @param err
 * @param af
 * @param src
 * @param dst
 * @param size
 * @return
 */
const char *dc_inet_ntop(const struct dc_posix_env *env, struct dc_error *err,
                         int af, const void *restrict src, char *restrict dst,
                         socklen_t size);

/**
 *
 * @param env
 * @param err
 * @param af
 * @param src
 * @param dst
 * @return
 */
int dc_inet_pton(const struct dc_posix_env *env, struct dc_error *err, int af,
                 const char *restrict src, void *restrict dst);


#ifdef __cplusplus
}
#endif


#endif //LIBDC_POSIX_ARPA_INET_H
