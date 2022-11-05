/*
 * Copyright 2022-2022 D'Arcy Smith.
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


#include "dc_posix/dc_ctype.h"
#include <ctype.h>


int dc_isalnum_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isalnum_l(c, locale);

    return ret_val;
}

int dc_isalpha_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isalpha_l(c, locale);

    return ret_val;
}

int dc_isblank_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isblank_l(c, locale);

    return ret_val;
}

int dc_iscntrl_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iscntrl_l(c, locale);

    return ret_val;
}

int dc_isdigit_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isdigit_l(c, locale);

    return ret_val;
}

int dc_isgraph_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isgraph_l(c, locale);

    return ret_val;
}

int dc_islower_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = islower_l(c, locale);

    return ret_val;
}

int dc_isprint_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isprint_l(c, locale);

    return ret_val;
}

int dc_ispunct_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ispunct_l(c, locale);

    return ret_val;
}

int dc_isspace_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isspace_l(c, locale);

    return ret_val;
}

int dc_isupper_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isupper_l(c, locale);

    return ret_val;
}

int dc_isxdigit_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = isxdigit_l(c, locale);

    return ret_val;
}

int dc_tolower_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = tolower_l(c, locale);

    return ret_val;
}

int dc_toupper_l(const struct dc_env *env, int c, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = toupper_l(c, locale);

    return ret_val;
}
