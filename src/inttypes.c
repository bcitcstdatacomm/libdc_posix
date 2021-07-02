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


#include "inttypes.h"
#include <errno.h>


intmax_t dc_strtoimax(const struct dc_posix_env *env,
                      int *err,
                      const char *restrict nptr,
                      char **restrict endptr,
                      int base)
{
    intmax_t  value;

    DC_TRACE(env);
    errno = 0;
    value = strtoimax(nptr, endptr, base);

    if(errno != 0)
    {
        *err = errno;
        DC_REPORT_ERROR(env, errno);
    }

    return value;
}

uintmax_t dc_strtoumax(const struct dc_posix_env *env,
                       int *err,
                       const char *restrict nptr,
                       char **restrict endptr,
                       int base)
{
    uintmax_t  value;

    DC_TRACE(env);
    errno = 0;
    value = strtoumax(nptr, endptr, base);
    *err  = errno;

    if(errno != 0)
    {
        DC_REPORT_ERROR(env, errno);
    }

    return value;
}

