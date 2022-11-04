#ifndef LIBDC_POSIX_DC_WCHAR_H
#define LIBDC_POSIX_DC_WCHAR_H


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
#include <wchar.h>

#ifdef __APPLE__
    #include <xlocale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif


size_t dc_mbsnrtowcs(const struct dc_env *env, struct dc_error *err, wchar_t *restrict dst, const char **restrict src, size_t nmc, size_t len, mbstate_t *restrict ps);
FILE *dc_open_wmemstream(const struct dc_env *env, struct dc_error *err, wchar_t **bufp, size_t *sizep);
wchar_t *dc_wcpcpy(const struct dc_env *env, struct dc_error *err, wchar_t *restrict ws1, const wchar_t *restrict ws2);
wchar_t *dc_wcpncpy(const struct dc_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n);
int dc_wcscasecmp(const struct dc_env *env, const wchar_t *ws1, const wchar_t *ws2);
int dc_wcscasecmp_l(const struct dc_env *env, const wchar_t *ws1, const wchar_t *ws2, locale_t locale);
int dc_wcscoll_l(const struct dc_env *env, struct dc_error *err, const wchar_t *ws1, const wchar_t *ws2, locale_t locale);
wchar_t *dc_wcsdup(const struct dc_env *env, struct dc_error *err, const wchar_t *string);
int dc_wcsncasecmp(const struct dc_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n);
int dc_wcsncasecmp_l(const struct dc_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n, locale_t locale);
size_t dc_wcsnlen(const struct dc_env *env, const wchar_t *ws, size_t maxlen);
size_t dc_wcsnrtombs(const struct dc_env *env, struct dc_error *err, char *restrict dst, const wchar_t **restrict src, size_t nwc, size_t len, mbstate_t *restrict ps);
size_t dc_wcsxfrm_l(const struct dc_env *env, struct dc_error *err, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n, locale_t locale);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_WCHAR_H
