#ifndef LIBDC_POSIX_SYS_DC_STAT_H
#define LIBDC_POSIX_SYS_DC_STAT_H

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

#include "dc_posix_env.h"
#include <sys/stat.h>
#include <sys/time.h>

/**
 *
 * @param env
 * @param err
 * @param path
 * @param mode
 * @return
 */
int dc_chmod(const struct dc_posix_env *env, struct dc_error *err,
             const char *path, mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param mode
 * @return
 */
int dc_fchmod(const struct dc_posix_env *env, struct dc_error *err, int fildes,
              mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param mode
 * @param flag
 * @return
 */
int dc_fchmodat(const struct dc_posix_env *env, struct dc_error *err, int fd,
                const char *path, mode_t mode, int flag);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @return
 */
int dc_fstat(const struct dc_posix_env *env, struct dc_error *err, int fildes,
             struct stat *buf);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param buf
 * @param flag
 * @return
 */
int dc_fstatat(const struct dc_posix_env *env, struct dc_error *err, int fd,
               const char *restrict path, struct stat *restrict buf, int flag);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param times
 * @return
 */
int dc_futimens(const struct dc_posix_env *env, struct dc_error *err, int fd,
                const struct timespec times[2]);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param buf
 * @return
 */
int dc_lstat(const struct dc_posix_env *env, struct dc_error *err,
             const char *restrict path, struct stat *restrict buf);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param mode
 * @return
 */
int dc_mkdir(const struct dc_posix_env *env, struct dc_error *err,
             const char *path, mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param mode
 * @return
 */
int dc_mkdirat(const struct dc_posix_env *env, struct dc_error *err, int fd,
               const char *path, mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param mode
 * @return
 */
int dc_mkfifo(const struct dc_posix_env *env, struct dc_error *err,
              const char *path, mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param mode
 * @return
 */
int dc_mkfifoat(const struct dc_posix_env *env, struct dc_error *err, int fd,
                const char *path, mode_t mode);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param mode
 * @param dev
 * @return
 */
int dc_mknod(const struct dc_posix_env *env, struct dc_error *err,
             const char *path, mode_t mode, dev_t dev);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param mode
 * @param dev
 * @return
 */
int dc_mknodat(const struct dc_posix_env *env, struct dc_error *err, int fd,
               const char *path, mode_t mode, dev_t dev);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param buf
 * @return
 */
int dc_stat(const struct dc_posix_env *env, struct dc_error *err,
            const char *restrict path, struct stat *restrict buf);

/**
 *
 * @param env
 * @param err
 * @param cmask
 * @return
 */
mode_t dc_umask(const struct dc_posix_env *env, mode_t cmask);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param times
 * @return
 */
int dc_utimes(const struct dc_posix_env *env, struct dc_error *err,
              const char *path, const struct timeval times[2]);

#endif // LIBDC_POSIX_SYS_DC_STAT_H
