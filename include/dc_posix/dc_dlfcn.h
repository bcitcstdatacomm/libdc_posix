#ifndef LIBDC_POSIX_DC_DLFCN_H
#define LIBDC_POSIX_DC_DLFCN_H

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

#include "dc_posix_env.h"
#include <dlfcn.h>

int dc_dlclose(const struct dc_posix_env *env, struct dc_error *err, void *handle);
char *dc_dlerror(const struct dc_posix_env *env);
void *dc_dlopen(const struct dc_posix_env *env, struct dc_error *err, const char *file, int mode);
void *dc_dlsym(const struct dc_posix_env *env, struct dc_error *err, void *restrict handle, const char *restrict name);

#endif // LIBDC_POSIX_DC_DLFCN_H
