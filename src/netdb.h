#ifndef LIBDC_POSIX_NETDB_H
#define LIBDC_POSIX_NETDB_H


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
