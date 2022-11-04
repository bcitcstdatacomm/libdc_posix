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


#include <dc_env/env.h>
#include <sys/stat.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_chmod(const struct dc_env *env, struct dc_error *err, const char *path, mode_t mode);
int dc_fchmod(const struct dc_env *env, struct dc_error *err, int fildes, mode_t mode);
int dc_fchmodat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, mode_t mode, int flag);
int dc_fstat(const struct dc_env *env, struct dc_error *err, int fildes, struct stat *buf);
int dc_fstatat(const struct dc_env *env, struct dc_error *err, int fd, const char *restrict path, struct stat *restrict buf, int flag);
int dc_futimens(const struct dc_env *env, struct dc_error *err, int fd, const struct timespec times[2]);
int dc_lstat(const struct dc_env *env, struct dc_error *err, const char *restrict path, struct stat *restrict buf);
int dc_mkdir(const struct dc_env *env, struct dc_error *err, const char *path, mode_t mode);
int dc_mkdirat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, mode_t mode);
int dc_mkfifo(const struct dc_env *env, struct dc_error *err, const char *path, mode_t mode);
int dc_stat(const struct dc_env *env, struct dc_error *err, const char *restrict path, struct stat *restrict buf);
mode_t dc_umask(const struct dc_env *env, mode_t cmask);
int dc_utimensat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, const struct timespec times[2], int flag);


#ifdef __cplusplus
}
#endif


// not on macOS
// int dc_mkfifoat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, mode_t mode);


#endif // LIBDC_POSIX_SYS_DC_STAT_H
