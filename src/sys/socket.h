#ifndef LIBDC_POSIX_SOCKET_H
#define LIBDC_POSIX_SOCKET_H


#include "../posix_env.h"
#include <sys/socket.h>


int dc_socket(const struct dc_posix_env *env, struct dc_error *err, int domain, int type, int protocol);
int dc_connect(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len);
int dc_setsockopt(const struct dc_posix_env *env, struct dc_error *err, int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int dc_bind(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len);
int dc_listen(const struct dc_posix_env *env, struct dc_error *err, int socket, int backlog);
int dc_accept(const struct dc_posix_env *env, struct dc_error *err, int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);


#endif // LIBDC_POSIX_SOCKET_H
