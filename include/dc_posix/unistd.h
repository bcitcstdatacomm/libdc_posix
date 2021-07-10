#ifndef LIBDC_POSIX_UNISTD_H
#define LIBDC_POSIX_UNISTD_H


/*
 * Copyright 2021-2021 D'Arcy Smith.
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


#include "posix_env.h"
#include <sys/types.h>


/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @return
 */
ssize_t dc_read(const struct dc_posix_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @return
 */
ssize_t dc_write(const struct dc_posix_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte);


/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_close(const struct dc_posix_env *env, struct dc_error *err, int fildes);


/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_dup(const struct dc_posix_env *env, struct dc_error *err, int fildes);


/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param fildes2
 * @return
 */
int dc_dup2(const struct dc_posix_env *env, struct dc_error *err, int fildes, int fildes2);


#endif // LIBDC_POSIX_UNISTD_H
