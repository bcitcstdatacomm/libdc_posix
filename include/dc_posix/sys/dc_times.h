#ifndef LIBDC_POSIX_SYS_DC_TIMES_H
#define LIBDC_POSIX_SYS_DC_TIMES_H

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

#include "dc_posix_env.h"
#include <sys/times.h>

/**
 *
 * @param env
 * @param err
 * @param buffer
 * @return
 */
clock_t dc_times(const struct dc_posix_env *env, struct dc_error *err,
                 struct tms *buffer);

#endif // LIBDC_POSIX_SYS_DC_TIMES_H
