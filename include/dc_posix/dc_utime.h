#ifndef LIBDC_POSIX_DC_UTIME_H
#define LIBDC_POSIX_DC_UTIME_H


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


#include <dc_env/env.h>
#include <utime.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_utime(const struct dc_env *env, struct dc_error *err, const char *path, const struct utimbuf *times);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_UTIME_H
