#ifndef LIBDC_POSIX_DC_STDLIB_H
#define LIBDC_POSIX_DC_STDLIB_H

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

#include "dc_posix_env.h"
#include <sys/types.h>

/**
 *
 * @param env
 * @param err
 * @param nelem
 * @param elsize
 * @return
 */
void *dc_calloc(const struct dc_posix_env *env, struct dc_error *err,
                size_t nelem, size_t elsize);

_Noreturn void dc_exit(const struct dc_posix_env *env, int status);

/**
 *
 * @param env
 * @param ptr
 * @param size
 */
void dc_free(const struct dc_posix_env *env, void *ptr, size_t size);

char *dc_getenv(const struct dc_posix_env *env, const char *name);

/**
 *
 * @param env
 * @param err
 * @param size
 * @return
 */
void *dc_malloc(const struct dc_posix_env *env, struct dc_error *err,
                size_t size);

void *dc_realloc(const struct dc_posix_env *env, struct dc_error *err, void *ptr, size_t size);

char *dc_realpath(const struct dc_posix_env *env, struct dc_error *err, const char *restrict file_name, char *restrict resolved_name);

#endif // LIBDC_POSIX_DC_STDLIB_H
