#ifndef LIBDC_POSIX_SYS_DC_IPC_H
#define LIBDC_POSIX_SYS_DC_IPC_H

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

#include "../dc_posix_env.h"
#include <sys/ipc.h>

key_t dc_ftok(const struct dc_posix_env *env, struct dc_error *err, const char *path, int id);

#endif // LIBDC_POSIX_SYS_DC_IPC_H