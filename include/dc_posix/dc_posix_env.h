#ifndef LIBDC_POSIX_DC_POSIX_ENV_H
#define LIBDC_POSIX_DC_POSIX_ENV_H

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-macros"
#define __STDC_WANT_LIB_EXT1__ 1
#pragma GCC diagnostic pop

#include <dc_error/error.h>
#include <stdbool.h>

#ifndef _POSIX_C_SOURCE
#error Requires a POSIX compatible system
#endif

struct dc_posix_env;

typedef void (*dc_posix_tracer)(const struct dc_posix_env *env,
                                const char *file_name,
                                const char *function_name, size_t line_number);

struct dc_posix_env;


/**
 *
 * @param env
 * @param tracer
 */
void dc_posix_env_init(struct dc_posix_env *env, dc_posix_tracer tracer);

/**
 *
 * @param env
 * @return
 */
bool dc_posix_env_is_zero_free(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @return
 */
dc_posix_tracer dc_posix_env_get_tracer(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param on
 */
void dc_posix_env_set_zero_free(struct dc_posix_env *env, bool on);

/**
 *
 * @param env
 * @param tracer
 */
void dc_posix_env_set_tracer(struct dc_posix_env *env, dc_posix_tracer tracer);

/**
 *
 * @param env
 * @param file_name
 * @param function_name
 * @param line_number
 */
void dc_posix_default_tracer(const struct dc_posix_env *env,
                             const char *file_name, const char *function_name,
                             size_t line_number);

// void dc_posix_default_error_inducer(const struct dc_posix_env *env, bool on);

/**
 *
 * @param env
 * @param file_name
 * @param function_name
 * @param line_number
 */
void dc_trace(const struct dc_posix_env *env, const char *file_name,
              const char *function_name, size_t line_number);

#define DC_TRACE(env) dc_trace((env), __FILE__, __func__, __LINE__)

#endif // LIBDC_POSIX_DC_POSIX_ENV_H
