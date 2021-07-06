#ifndef LIBDC_POSIX_NETDB_H
#define LIBDC_POSIX_NETDB_H


#include "posix_env.h"
#include <netdb.h>



/**
 *
 * @param env
 * @param err
 * @param ai
 */
void dc_freeaddrinfo(const struct dc_posix_env *env,
                     struct addrinfo           *ai);


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
int dc_getaddrinfo(const struct dc_posix_env  *env,
                   struct dc_error            *err,
                   const char                 *restrict nodename,
                   const char                 *restrict servname,
                   const struct addrinfo      *restrict hints,
                   struct addrinfo           **restrict res);


#endif //LIBDC_POSIX_NETDB_H
