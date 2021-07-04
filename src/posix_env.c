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
#include <string.h>


void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const struct dc_posix_env *env, const struct dc_error *err))
{
    // can't used dc_memset yet
    memset(env, 0, sizeof(struct dc_posix_env));
    env->error_reporter = error_reporter;
}

void dc_err_reset(struct dc_error *err)
{
    memset(err, 0, sizeof(struct dc_error));
}

static void setup_error(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, dc_error_type type)
{
    err->file_name     = file_name;
    err->function_name = function_name;
    err->line_number   = line_number;
    err->type          = type;
}

void dc_err_errno(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, errno_t err_code)
{
    setup_error(err, file_name, function_name, line_number, DC_ERROR_ERRNO);
    err->errno_code = err_code;
}

void dc_err_system(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, int err_code)
{
    setup_error(err, file_name, function_name, line_number, DC_ERROR_SYSTEM);
    err->err_code = err_code;
}

void dc_err_user(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, int err_code)
{
    setup_error(err, file_name, function_name, line_number, DC_ERROR_USER);
    err->err_code = err_code;
}
