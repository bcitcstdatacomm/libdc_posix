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

#include "dc_inttypes.h"
#include "dc_posix_env.h"

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strtoimax.html
intmax_t dc_strtoimax(const struct dc_posix_env *env,
                      struct dc_error *err,
                      const char *restrict nptr,
                      char **restrict endptr,
                      int base)
{
    intmax_t value;

    DC_TRACE(env);
    dc_error_reset(err);
    errno = 0;
    value = strtoimax(nptr, endptr, base);

    if(value == 0 || value == INTMAX_MIN || value == INTMAX_MAX)
    {
        if(errno != 0)
        {
            DC_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return value;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strtoimax.html
uintmax_t dc_strtoumax(const struct dc_posix_env *env,
                       struct dc_error *err,
                       const char *restrict nptr,
                       char **restrict endptr,
                       int base)
{
    uintmax_t value;

    DC_TRACE(env);
    dc_error_reset(err);
    errno = 0;
    value = strtoumax(nptr, endptr, base);

    if(value == 0 || value == UINTMAX_MAX)
    {
        if(errno != 0)
        {
            DC_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return value;
}
