#ifndef LIBDC_POSIX_DC_POSIX_ENV_H
#define LIBDC_POSIX_DC_POSIX_ENV_H

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-macros"
#define __STDC_WANT_LIB_EXT1__ 1
#pragma GCC diagnostic pop

#include <dc_error/error.h>
#include <stdbool.h>

#ifndef _POSIX_C_SOURCE
#error Requires a POSIX compatible system
#endif

struct dc_posix_env
{
    bool zero_free;
    bool null_free;

    void (*error_reporter)(const struct dc_posix_env *env,
                           const struct dc_error *err);

    void (*tracer)(const struct dc_posix_env *env, const char *file_name,
                   const char *function_name, size_t line_number);
};

/**
 *
 * @param env
 * @param error_reporter
 */
void dc_posix_env_init(struct dc_posix_env *env,
                       void (*error_reporter)(const struct dc_posix_env *env,
                                              const struct dc_error *err));

/**
 *
 * @param env
 * @param err
 */
void dc_posix_default_error_reporter(const struct dc_posix_env *env,
                                     const struct dc_error *err);

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
