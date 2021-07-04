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
#include <stdlib.h>


static void setup_error(struct dc_error *err, dc_error_type type, const char *file_name, const char *function_name, size_t line_number, const char *msg);


void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const struct dc_posix_env *env, const struct dc_error *err))
{
    memset(env, 0, sizeof(struct dc_posix_env));
    env->error_reporter = error_reporter;
}

void dc_error_init(struct dc_error *err)
{
    memset(err, 0, sizeof(struct dc_error));
}


void dc_error_reset(struct dc_error *err)
{
    if(err->message)
    {
        free(err->message);
    }

    dc_error_init(err);
}


static void setup_error(struct dc_error *err, dc_error_type type, const char *file_name, const char *function_name, size_t line_number, const char *msg)
{
    char *saved_msg;

    saved_msg = malloc(strlen(msg) + 1);

    if(saved_msg)
    {
        strcpy(saved_msg, msg);
    }

    err->type          = type;
    err->file_name     = file_name;
    err->function_name = function_name;
    err->line_number   = line_number;
    err->message       = saved_msg;
}


void dc_error_errno(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, errno_t err_code)
{
    char *msg;

    msg = strerror(err_code);
    setup_error(err, DC_ERROR_ERRNO, file_name, function_name, line_number, msg);
    err->errno_code = err_code;
}


void dc_error_system(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, const char *msg, int err_code)
{
    setup_error(err, DC_ERROR_SYSTEM, file_name, function_name, line_number, msg);
    err->err_code = err_code;
}


void dc_error_user(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, const char *msg, int err_code)
{
    setup_error(err, DC_ERROR_USER, file_name, function_name, line_number, msg);
    err->err_code = err_code;
}
