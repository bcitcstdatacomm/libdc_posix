#ifndef LIBDC_POSIX_DC_PWD_H
#define LIBDC_POSIX_DC_PWD_H


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
#include <sys/types.h>


#ifdef __cplusplus
extern "C" {
#endif


struct passwd *dc_getpwnam(const struct dc_env *env, struct dc_error *err, const char *name);
int dc_getpwnam_r(const struct dc_env *env, struct dc_error *err, const char *name, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result);
struct passwd *dc_getpwuid(const struct dc_env *env, struct dc_error *err, uid_t uid);
int dc_getpwuid_r(const struct dc_env *env, struct dc_error *err, uid_t uid, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_PWD_H
