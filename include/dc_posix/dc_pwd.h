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


#include "dc_posix_env.h"
#include <pwd.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 */
void dc_endpwent(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @return
 */
struct passwd *dc_getpwent(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param name
 * @return
 */
struct passwd *dc_getpwnam(const struct dc_posix_env *env, struct dc_error *err, const char *name);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param pwd
 * @param buffer
 * @param bufsize
 * @param result
 * @return
 */
int dc_getpwnam_r(const struct dc_posix_env *env, struct dc_error *err, const char *name, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result);

/**
 *
 * @param env
 * @param err
 * @param uid
 * @return
 */
struct passwd *dc_getpwuid(const struct dc_posix_env *env, struct dc_error *err, uid_t uid);

/**
 *
 * @param env
 * @param err
 * @param uid
 * @param pwd
 * @param buffer
 * @param bufsize
 * @param result
 * @return
 */
int dc_getpwuid_r(const struct dc_posix_env *env, struct dc_error *err, uid_t uid, struct passwd *pwd, char *buffer, size_t bufsize, struct passwd **result);

/**
 *
 * @param env
 * @param err
 */
void dc_setpwent(const struct dc_posix_env *env, struct dc_error *err);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_PWD_H
