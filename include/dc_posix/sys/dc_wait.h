#ifndef LIBDC_POSIX_SYS_DC_WAIT_H
#define LIBDC_POSIX_SYS_DC_WAIT_H

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

#include "../dc_posix_env.h"
#include <sys/wait.h>
#include <sys/signal.h>

pid_t dc_wait(const struct dc_posix_env *env, struct dc_error *err,
              int *stat_loc);
int dc_waitid(const struct dc_posix_env *env, struct dc_error *err,
              idtype_t idtype, id_t id, siginfo_t *infop, int options);
pid_t dc_waitpid(const struct dc_posix_env *env, struct dc_error *err,
                 pid_t pid, int *stat_loc, int options);

#endif // LIBDC_POSIX_SYS_DC_WAIT_H
