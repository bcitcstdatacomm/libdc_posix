#ifndef LIBDC_POSIX_DC_STRINGS_H
#define LIBDC_POSIX_DC_STRINGS_H


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
#include <strings.h>
#include <xlocale.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_strcasecmp(const struct dc_env *env, const char *s1, const char *s2);
int dc_strcasecmp_l(const struct dc_env *env, const char *s1, const char *s2, locale_t locale);
int dc_strncasecmp(const struct dc_env *env, const char *s1, const char *s2, size_t n);
int dc_strncasecmp_l(const struct dc_env *env, const char *s1, const char *s2, size_t n, locale_t locale);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_STRINGS_H
