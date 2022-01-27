#ifndef LIBDC_POSIX_SYS_DC_SOCKET_H
#define LIBDC_POSIX_SYS_DC_SOCKET_H

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
#include <sys/socket.h>

/**
 *
 * @param env
 * @param err
 * @param domain
 * @param type
 * @param protocol
 * @return
 */
int dc_socket(const struct dc_posix_env *env, struct dc_error *err, int domain,
              int type, int protocol);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param address
 * @param address_len
 * @return
 */
int dc_connect(const struct dc_posix_env *env, struct dc_error *err, int socket,
               const struct sockaddr *address, socklen_t address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param level
 * @param option_name
 * @param option_value
 * @param option_len
 * @return
 */
int dc_getsockopt(const struct dc_posix_env *env, struct dc_error *err,
                  int socket, int level, int option_name,
                  void *restrict option_value, socklen_t *restrict option_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param level
 * @param option_name
 * @param option_value
 * @param option_len
 * @return
 */
int dc_setsockopt(const struct dc_posix_env *env, struct dc_error *err,
                  int socket, int level, int option_name,
                  const void *option_value, socklen_t option_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param address
 * @param address_len
 * @return
 */
int dc_bind(const struct dc_posix_env *env, struct dc_error *err, int socket,
            const struct sockaddr *address, socklen_t address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param backlog
 * @return
 */
int dc_listen(const struct dc_posix_env *env, struct dc_error *err, int socket,
              int backlog);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param address
 * @param address_len
 * @return
 */
int dc_accept(const struct dc_posix_env *env, struct dc_error *err, int socket,
              struct sockaddr *restrict address,
              socklen_t *restrict address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param address
 * @param address_len
 * @return
 */
int dc_getpeername(const struct dc_posix_env *env, struct dc_error *err,
                   int socket, struct sockaddr *restrict address,
                   socklen_t *restrict address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param address
 * @param address_len
 * @return
 */
int dc_getsockname(const struct dc_posix_env *env, struct dc_error *err,
                   int socket, struct sockaddr *restrict address,
                   socklen_t *restrict address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param buffer
 * @param length
 * @param flags
 * @return
 */
ssize_t dc_recv(const struct dc_posix_env *env, struct dc_error *err,
                int socket, void *buffer, size_t length, int flags);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param buffer
 * @param length
 * @param flags
 * @param address
 * @param address_len
 * @return
 */
ssize_t dc_recvfrom(const struct dc_posix_env *env, struct dc_error *err,
                    int socket, void *restrict buffer, size_t length, int flags,
                    struct sockaddr *restrict address,
                    socklen_t *restrict address_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param message
 * @param flags
 * @return
 */
ssize_t dc_recvmsg(const struct dc_posix_env *env, struct dc_error *err,
                   int socket, struct msghdr *message, int flags);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param buffer
 * @param length
 * @param flags
 * @return
 */
ssize_t dc_send(const struct dc_posix_env *env, struct dc_error *err,
                int socket, const void *buffer, size_t length, int flags);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param message
 * @param flags
 * @return
 */
ssize_t dc_sendmsg(const struct dc_posix_env *env, struct dc_error *err,
                   int socket, const struct msghdr *message, int flags);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param message
 * @param length
 * @param flags
 * @param dest_addr
 * @param dest_len
 * @return
 */
ssize_t dc_sendto(const struct dc_posix_env *env, struct dc_error *err,
                  int socket, const void *message, size_t length, int flags,
                  const struct sockaddr *dest_addr, socklen_t dest_len);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @param how
 * @return
 */
int dc_shutdown(const struct dc_posix_env *env, struct dc_error *err,
                int socket, int how);

/**
 *
 * @param env
 * @param err
 * @param socket
 * @return
 */
int dc_sockatmark(const struct dc_posix_env *env, struct dc_error *err,
                  int socket);

/**
 *
 * @param env
 * @param err
 * @param domain
 * @param type
 * @param protocol
 * @param socket_vector
 * @return
 */
int dc_socketpair(const struct dc_posix_env *env, struct dc_error *err,
                  int domain, int type, int protocol, int socket_vector[2]);

#endif // LIBDC_POSIX_SYS_DC_SOCKET_H
