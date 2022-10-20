#ifndef LIBDC_POSIX_DC_GRP_H
#define LIBDC_POSIX_DC_GRP_H


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
#include <grp.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 */
void dc_endgrent(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @return
 */
struct group *dc_getgrent(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param gid
 * @return
 */
struct group *dc_getgrgid(const struct dc_posix_env *env, struct dc_error *err, gid_t gid);

/**
 *
 * @param env
 * @param err
 * @param gid
 * @param grp
 * @param buffer
 * @param bufsize
 * @param result
 * @return
 */
int dc_getgrgid_r(const struct dc_posix_env *env, struct dc_error *err, gid_t gid, struct group *grp, char *buffer, size_t bufsize, struct group **result);

/**
 *
 * @param env
 * @param err
 * @param name
 * @return
 */
struct group *dc_getgrnam(const struct dc_posix_env *env, struct dc_error *err, const char *name);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param grp
 * @param buffer
 * @param bufsize
 * @param result
 * @return
 */
int dc_getgrnam_r(const struct dc_posix_env *env, struct dc_error *err, const char *name, struct group *grp, char *buffer, size_t bufsize, struct group **result);

/**
 *
 * @param env
 * @param err
 */
void dc_setgrent(const struct dc_posix_env *env, struct dc_error *err);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_GRP_H
