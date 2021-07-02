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


#include <string.h>
#include "posix_env.h"


void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const char *file_name, const char *function_name, size_t line_number, int err))
{
    memset(env, 0, sizeof(struct dc_posix_env));
    env->error_reporter = error_reporter;
}
