#ifndef LIBDC_POSIX_POSIX_ENV_H
#define LIBDC_POSIX_POSIX_ENV_H


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


#include <errno.h>
#include <stdbool.h>
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
struct dc_posix_env
{
    bool zero_malloc;
    bool zero_free;
    bool null_free;
    void (*error_reporter)(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number, int err);
    void (*tracer)(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number);
};
#pragma GCC diagnostic pop


/**
 * 
 * @param env
 * @param error_reporter
 */
void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number, int err));


#define DC_REPORT_ERROR(env, err) if((env)->error_reporter) (env)->error_reporter((env), __FILE__, __func__, __LINE__, err)
#define DC_TRACE(env) if((env)->tracer) (env)->tracer((env), __FILE__, __func__, __LINE__)


#endif // LIBDC_POSIX_POSIX_ENV_H
