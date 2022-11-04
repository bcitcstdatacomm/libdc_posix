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


#include "dc_posix/dc_strings.h"
#include <strings.h>

#if (defined __APPLE__) || (defined __FreeBSD__)
    #include <xlocale.h>
#endif


int dc_strcasecmp(const struct dc_env *env, const char *s1, const char *s2)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strcasecmp(s1, s2);

    return ret_val;
}

int dc_strcasecmp_l(const struct dc_env *env, const char *s1, const char *s2, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strcasecmp_l(s1, s2, locale);

    return ret_val;
}

int dc_strncasecmp(const struct dc_env *env, const char *s1, const char *s2, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strncasecmp(s1, s2, n);

    return ret_val;
}

int dc_strncasecmp_l(const struct dc_env *env, const char *s1, const char *s2, size_t n, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strncasecmp_l(s1, s2, n, locale);

    return ret_val;
}
