#ifndef LIBDC_POSIX_DC_SOCKET_H
#define LIBDC_POSIX_DC_SOCKET_H


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


#include "../dc_posix_env.h"
#include <sys/socket.h>


int dc_socket(const struct dc_posix_env *env, struct dc_error *err, int domain, int type, int protocol);
int dc_connect(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len);
int dc_setsockopt(const struct dc_posix_env *env, struct dc_error *err, int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int dc_bind(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len);
int dc_listen(const struct dc_posix_env *env, struct dc_error *err, int socket, int backlog);
int dc_accept(const struct dc_posix_env *env, struct dc_error *err, int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);


#endif // LIBDC_POSIX_DC_SOCKET_H
