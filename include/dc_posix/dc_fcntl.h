#ifndef LIBDC_POSIX_DC_FCNTL_H
#define LIBDC_POSIX_DC_FCNTL_H

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
#include <fcntl.h>

int dc_creat(const struct dc_posix_env *env, struct dc_error *err, const char *path, mode_t mode);
// int dc_fcntl(const struct dc_posix_env *env, struct dc_error *err, int fildes, int cmd, ...);
int dc_open(const struct dc_posix_env *env, struct dc_error *err, const char *path, unsigned int oflag, ...);
int dc_openat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, unsigned int oflag, ...);
// int dc_posix_fadvise(const struct dc_posix_env *env, struct dc_error *err, int fd, off_t offset, off_t len, int advice);
// int dc_posix_fallocate(const struct dc_posix_env *env, struct dc_error *err, int fd, off_t offset, off_t len);

#define DC_O_APPEND (unsigned int)O_APPEND
#define DC_O_CLOEXEC (unsigned int)O_CLOEXEC
#define DC_O_CREAT (unsigned int)O_CREAT
#define DC_O_DIRECTORY (unsigned int)O_DIRECTORY
#define DC_O_DSYNC (unsigned int)O_DSYNC
#define DC_O_EXCL (unsigned int)O_EXCL
#define DC_O_NOCTTY (unsigned int)O_NOCTTY
#define DC_O_NOFOLLOW (unsigned int)O_NOFOLLOW
#define DC_O_NONBLOCK (unsigned int)O_NONBLOCK
#define DC_O_SYNC (unsigned int)O_SYNC
#define DC_O_TRUNC (unsigned int)O_TRUNC
#define DC_O_RDONLY (unsigned int)O_RDONLY
#define DC_O_WRONLY (unsigned int)O_WRONLY
#define DC_O_RDWR (unsigned int)O_RDWR
#define DC_O_CLOEXEC (unsigned int)O_CLOEXEC
#define DC_O_RSYNC (unsigned int)O_RSYNC
#define DC_O_EXEC (unsigned int)O_EXEC
#define DC_O_SEARCH (unsigned int)O_SEARCH

#define DC_S_IRWXU (mode_t) S_IRWXU
#define DC_S_IRUSR (mode_t) S_IRUSR
#define DC_S_IWUSR (mode_t) S_IWUSR
#define DC_S_IXUSR (mode_t) S_IXUSR
#define DC_S_IRWXG (mode_t) S_IRWXG
#define DC_S_IRGRP (mode_t) S_IRGRP
#define DC_S_IWGRP (mode_t) S_IWGRP
#define DC_S_IXGRP (mode_t) S_IXGRP
#define DC_S_IRWXO (mode_t) S_IRWXO
#define DC_S_IROTH (mode_t) S_IROTH
#define DC_S_IWOTH (mode_t) S_IWOTH
#define DC_S_IXOTH (mode_t) S_IXOTH
#define DC_S_ISUID (mode_t) S_ISUID
#define DC_S_ISGID (mode_t) S_ISGID
#define DC_S_ISVTX (mode_t) S_ISVTX

#endif // LIBDC_POSIX_DC_FCNTL_H
