#ifndef LIBDC_POSIX_DC_WCTYPE_H
#define LIBDC_POSIX_DC_WCTYPE_H


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


#include <dc_env/env.h>
#include <wctype.h>

#if (defined __APPLE__) || (defined __FreeBSD__)
    #include <xlocale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif


int dc_iswalnum_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswalpha_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswblank_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswcntrl_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswctype_l(const struct dc_env *env, wint_t wc, wctype_t charclass, locale_t locale);
int dc_iswdigit_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswgraph_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswlower_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswprint_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswpunct_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswspace_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswupper_l(const struct dc_env *env, wint_t wc, locale_t locale);
int dc_iswxdigit_l(const struct dc_env *env, wint_t wc, locale_t locale);
wint_t dc_towctrans_l(const struct dc_env *env, wint_t wc, wctrans_t desc, locale_t locale);
wint_t dc_towlower_l(const struct dc_env *env, wint_t wc, locale_t locale);
wint_t dc_towupper_l(const struct dc_env *env, wint_t wc, locale_t locale);
wctrans_t dc_wctrans_l(const struct dc_env *env, struct dc_error *err, const char *charclass, locale_t locale);
wctype_t dc_wctype_l(const struct dc_env *env, const char *property, locale_t locale);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_WCTYPE_H
