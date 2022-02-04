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

#include "dc_netdb.h"

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/freeaddrinfo.html
void dc_freeaddrinfo(const struct dc_posix_env *env, struct addrinfo *ai)
{
    DC_TRACE(env);
    freeaddrinfo(ai);
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/freeaddrinfo.html
int dc_getaddrinfo(const struct dc_posix_env *env,
                   struct dc_error           *err,
                   const char * restrict nodename,
                   const char * restrict servname,
                   const struct addrinfo * restrict hints,
                   struct addrinfo ** restrict res)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getaddrinfo(nodename, servname, hints, res);

    if(ret_val != 0)
    {
        if(errno == 0)
        {
            const char *msg;

            switch(ret_val)
            {
                case EAI_AGAIN:
                {
                    msg = "The name could not be resolved at this time. Future attempts may succeed.";
                    break;
                }
                case EAI_BADFLAGS:
                {
                    msg = "The flags parameter had an invalid value.";
                    break;
                }
                case EAI_FAIL:
                {
                    msg = "A non-recoverable error occurred when attempting to resolve the name.";
                    break;
                }
                case EAI_FAMILY:
                {
                    msg = "The address family was not recognized.";
                    break;
                }
                case EAI_MEMORY:
                {
                    msg = "There was a memory allocation failure when trying to allocate storage for the return value.";
                    break;
                }
                case EAI_NONAME:
                {
                    msg = "The name does not resolve for the supplied parameters.";
                    break;
                }
                case EAI_SERVICE:
                {
                    msg = "The service passed was not recognized for the specified socket type.";
                    break;
                }
                case EAI_SOCKTYPE:
                {
                    msg = "The intended socket type was not recognized.";
                    break;
                }
                default:
                {
                    msg = "Unknown Error from wordexp";
                }
            }

            DC_ERROR_RAISE_SYSTEM(err, msg, ret_val);
        }
        else
        {
            DC_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return ret_val;
}
