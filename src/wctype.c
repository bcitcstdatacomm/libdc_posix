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


#include "dc_posix/dc_wctype.h"


int dc_iswalnum_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswalnum_l(wc, locale);

    return ret_val;
}

int dc_iswalpha_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswalpha_l(wc, locale);

    return ret_val;
}

int dc_iswblank_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswblank_l(wc, locale);

    return ret_val;
}

int dc_iswcntrl_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswcntrl_l(wc, locale);

    return ret_val;
}

int dc_iswctype_l(const struct dc_env *env, wint_t wc, wctype_t charclass, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswctype_l(wc, charclass, locale);

    return ret_val;
}

int dc_iswdigit_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswdigit_l(wc, locale);

    return ret_val;
}

int dc_iswgraph_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswgraph_l(wc, locale);

    return ret_val;
}

int dc_iswlower_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswlower_l(wc, locale);

    return ret_val;
}

int dc_iswprint_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswprint_l(wc, locale);

    return ret_val;
}

int dc_iswpunct_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswpunct_l(wc, locale);

    return ret_val;
}

int dc_iswspace_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswspace_l(wc, locale);

    return ret_val;
}

int dc_iswupper_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswupper_l(wc, locale);

    return ret_val;
}

int dc_iswxdigit_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iswxdigit_l(wc, locale);

    return ret_val;
}

wint_t dc_towctrans_l(const struct dc_env *env, wint_t wc, wctrans_t desc, locale_t locale)
{
    wint_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = towctrans_l(wc, desc, locale);

    return ret_val;
}

wint_t dc_towlower_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    wint_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = towlower_l(wc, locale);

    return ret_val;
}

wint_t dc_towupper_l(const struct dc_env *env, wint_t wc, locale_t locale)
{
    wint_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = towupper_l(wc, locale);

    return ret_val;
}

wctrans_t dc_wctrans_l(const struct dc_env *env, struct dc_error *err, const char *charclass, locale_t locale)
{
    wctrans_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = wctrans_l(charclass, locale);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wctype_t dc_wctype_l(const struct dc_env *env, const char *property, locale_t locale)
{
    wctype_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = wctype_l(property, locale);

    return ret_val;
}
