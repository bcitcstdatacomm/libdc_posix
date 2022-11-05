#ifndef LIBDC_POSIX_NET_DC_IF_H
#define LIBDC_POSIX_NET_DC_IF_H


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
#include <net/if.h>


#ifdef __cplusplus
extern "C" {
#endif


void dc_if_freenameindex(const struct dc_env *env, struct if_nameindex *ptr);
char *dc_if_indextoname(const struct dc_env *env, struct dc_error *err, unsigned ifindex, char *ifname);
struct if_nameindex *dc_if_nameindex(const struct dc_env *env, struct dc_error *err);
unsigned dc_if_nametoindex(const struct dc_env *env, const char *ifname);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_NET_DC_IF_H
