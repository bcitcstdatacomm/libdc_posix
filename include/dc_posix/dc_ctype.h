#ifndef LIBDC_POSIX_DC_CTYPE_H
#define LIBDC_POSIX_DC_CTYPE_H


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
#include <ctype.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_isalnum_l(const struct dc_env *env, int c, locale_t locale);
int dc_isalpha_l(const struct dc_env *env, int c, locale_t locale);
int dc_isblank_l(const struct dc_env *env, int c, locale_t locale);
int dc_iscntrl_l(const struct dc_env *env, int c, locale_t locale);
int dc_isdigit_l(const struct dc_env *env, int c, locale_t locale);
int dc_isgraph_l(const struct dc_env *env, int c, locale_t locale);
int dc_islower_l(const struct dc_env *env, int c, locale_t locale);
int dc_isprint_l(const struct dc_env *env, int c, locale_t locale);
int dc_ispunct_l(const struct dc_env *env, int c, locale_t locale);
int dc_isspace_l(const struct dc_env *env, int c, locale_t locale);
int dc_isupper_l(const struct dc_env *env, int c, locale_t locale);
int dc_isxdigit_l(const struct dc_env *env, int c, locale_t locale);
int dc_tolower_l(const struct dc_env *env, int c, locale_t locale);
int dc_toupper_l(const struct dc_env *env, int c, locale_t locale);

#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_CTYPE_H
