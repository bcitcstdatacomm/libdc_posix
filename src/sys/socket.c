#include "socket.h"


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/socket.html
int dc_socket(const struct dc_posix_env *env, struct dc_error *err, int domain, int type, int protocol)
{
    int fd;

    DC_TRACE(env);
    errno = 0;
    fd    = socket(domain, type, protocol);

    if(fd == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return fd;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/connect.html
int dc_connect(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = connect(socket, address, address_len);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/setsockopt.html
int dc_setsockopt(const struct dc_posix_env *env, struct dc_error *err, int socket, int level, int option_name, const void *option_value, socklen_t option_len)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setsockopt(socket, level, option_name, option_value, option_len);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/bind.html
int dc_bind(const struct dc_posix_env *env, struct dc_error *err, int socket, const struct sockaddr *address, socklen_t address_len)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = bind(socket, address, address_len);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/listen.html
int dc_listen(const struct dc_posix_env *env, struct dc_error *err, int socket, int backlog)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = listen(socket, backlog);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/accept.html
int dc_accept(const struct dc_posix_env *env, struct dc_error *err, int socket, struct sockaddr *restrict address, socklen_t *restrict address_len)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = accept(socket, address, address_len);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}
