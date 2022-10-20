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


#include "dc_posix/dc_posix_env.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct dc_posix_env
{
    bool zero_free;
    dc_posix_tracer tracer;
};

struct dc_posix_env *dc_posix_env_create(struct dc_error *err, bool zero_free, dc_posix_tracer tracer)
{
    struct dc_posix_env *env;

    env = malloc(sizeof(struct dc_posix_env));  // NOLINT(clang-analyzer-unix.Malloc)

    if(env == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
    else
    {
        dc_posix_env_init(env, zero_free, tracer);
    }

    return env;
}

void dc_posix_env_init(struct dc_posix_env *env, bool zero_free, dc_posix_tracer tracer)
{
    env->zero_free = zero_free;
    env->tracer = tracer;
}

bool dc_posix_env_is_zero_free(const struct dc_posix_env *env)
{
    DC_TRACE(env);

    return env->zero_free;
}

dc_posix_tracer dc_posix_env_get_tracer(const struct dc_posix_env *env)
{
    DC_TRACE(env);

    return env->tracer;
}

void dc_posix_env_set_zero_free(struct dc_posix_env *env, bool on)
{
    DC_TRACE(env);

    env->zero_free = on;
}

void dc_posix_env_set_tracer(struct dc_posix_env *env, dc_posix_tracer tracer)
{
    DC_TRACE(env);

    env->tracer = tracer;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void dc_posix_default_tracer(const struct dc_posix_env *env,
                             const char *file_name,
                             const char *function_name,
                             size_t line_number)
{
    fprintf(stdout, "TRACE: %s : %s : @ %zu\n", file_name, function_name, line_number); // NOLINT(cert-err33-c)
}
#pragma GCC diagnostic pop

void dc_trace(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number)
{
    if(env->tracer != NULL)
    {
        env->tracer(env, file_name, function_name, line_number);
    }
}
