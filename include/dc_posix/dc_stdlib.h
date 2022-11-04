#ifndef LIBDC_POSIX_DC_STDLIB_H
#define LIBDC_POSIX_DC_STDLIB_H


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


#include <dc_env/env.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_getsubopt(const struct dc_env *env, struct dc_error *err, char **optionp, char * const *keylistp, char **valuep);
char *dc_mkdtemp(const struct dc_env *env, struct dc_error *err, char *template);
int dc_mkstemp(const struct dc_env *env, struct dc_error *err, char *template);
int dc_setenv(const struct dc_env *env, struct dc_error *err, const char *envname, const char *envval, int overwrite);
int dc_unsetenv(const struct dc_env *env, struct dc_error *err, const char *name);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_STDLIB_H
