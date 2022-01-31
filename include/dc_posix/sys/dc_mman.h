#ifndef LIBDC_POSIX_SYS_DC_MMAN_H
#define LIBDC_POSIX_SYS_DC_MMAN_H

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

#include "../dc_posix_env.h"
#include <sys/types.h>

int dc_mlock(const struct dc_posix_env *env, struct dc_error *err,
             const void *addr, size_t len);
int dc_mlockall(const struct dc_posix_env *env, struct dc_error *err,
                int flags);
void *dc_mmap(const struct dc_posix_env *env, struct dc_error *err, void *addr,
              size_t len, int prot, int flags, int fildes, off_t off);
int dc_mprotect(const struct dc_posix_env *env, struct dc_error *err,
                void *addr, size_t len, int prot);
int dc_msync(const struct dc_posix_env *env, struct dc_error *err, void *addr,
             size_t len, int flags);
int dc_munlock(const struct dc_posix_env *env, struct dc_error *err,
               const void *addr, size_t len);
int dc_munlockall(const struct dc_posix_env *env, struct dc_error *err);
int dc_munmap(const struct dc_posix_env *env, struct dc_error *err, void *addr,
              size_t len);
int dc_posix_madvise(const struct dc_posix_env *env, struct dc_error *err,
                     void *addr, size_t len, int advice);
// int dc_posix_mem_offset(const struct dc_posix_env *env, struct dc_error *err,
// const void *restrict addr, size_t len, off_t *restrict off, size_t *restrict
// contig_len, int *restrict fildes); int dc_posix_typed_mem_get_info(const
// struct dc_posix_env *env, struct dc_error *err, int fildes, struct
// posix_typed_mem_info *info); int dc_posix_typed_mem_open(const struct
// dc_posix_env *env, struct dc_error *err, const char *name, int oflag, int
// tflag);
int dc_shm_open(const struct dc_posix_env *env, struct dc_error *err,
                const char *name, int oflag, mode_t mode);
int dc_shm_unlink(const struct dc_posix_env *env, struct dc_error *err,
                  const char *name);

/*
int dc_select(const struct dc_posix_env *env, struct dc_error *err, int nfds,
              fd_set *restrict readfds, fd_set *restrict writefds,
              fd_set *restrict errorfds, struct timeval *restrict timeout);
*/

#endif // LIBDC_POSIX_SYS_DC_SELECT_H
