#ifndef LIBDC_POSIX_DC_DIRENT_H
#define LIBDC_POSIX_DC_DIRENT_H


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
#include <dirent.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
*
* @param env
* @param d1
* @param d2
* @return
*/
int dc_alphasort(const struct dc_posix_env *env, const struct dirent **d1, const struct dirent **d2);

/**
 *
 * @param env
 * @param err
 * @param dirp
 * @return
 */
int dc_closedir(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp);

/**
 *
 * @param env
 * @param err
 * @param dirp
 * @return
 */
int dc_dirfd(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @return
 */
DIR *dc_fdopendir(const struct dc_posix_env *env, struct dc_error *err, int fd);

/**
 *
 * @param env
 * @param err
 * @param dirname
 * @return
 */
DIR *dc_opendir(const struct dc_posix_env *env, struct dc_error *err, const char *dirname);

/**
 *
 * @param env
 * @param err
 * @param dirp
 * @return
 */
struct dirent *dc_readdir(const struct dc_posix_env *env, struct dc_error *err, DIR *dirp);

/**
 *
 * @param env
 * @param dirp
 */
void dc_rewinddir(const struct dc_posix_env *env, DIR *dirp);

/**
 *
 * @param env
 * @param err
 * @param dir
 * @param namelist
 * @param sel
 * @param compar
 * @return
 */
int dc_scandir(const struct dc_posix_env *env, struct dc_error *err, const char *dir, struct dirent ***namelist, int (*sel)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **));

/**
 *
 * @param env
 * @param dirp
 * @param loc
 */
void dc_seekdir(const struct dc_posix_env *env, DIR *dirp, long loc);

/**
 *
 * @param env
 * @param dirp
 * @return
 */
long dc_telldir(const struct dc_posix_env *env, DIR *dirp);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_DIRENT_H
