#ifndef LIBDC_POSIX_DC_NDBM_H
#define LIBDC_POSIX_DC_NDBM_H

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

#include "dc_posix_env.h"
#include <sys/types.h>
#include <ndbm.h>


int dc_dbm_clearerr(const struct dc_posix_env *env, struct dc_error *err,
                    DBM *db);
void dc_dbm_close(const struct dc_posix_env *env, struct dc_error *err,
                  DBM *db);
int dc_dbm_delete(const struct dc_posix_env *env, struct dc_error *err, DBM *db,
                  datum key);
int dc_dbm_error(const struct dc_posix_env *env, DBM *db);
datum dc_dbm_fetch(const struct dc_posix_env *env, struct dc_error *err,
                   DBM *db, datum key);
datum dc_dbm_firstkey(const struct dc_posix_env *env, struct dc_error *err,
                      DBM   *db);
datum dc_dbm_nextkey(const struct dc_posix_env *env, struct dc_error *err,
                     DBM *db);
DBM *dc_dbm_open(const struct dc_posix_env *env, struct dc_error *err,
                 const char *file, int open_flags, mode_t file_mode);
int dc_dbm_store(const struct dc_posix_env *env, struct dc_error *err, DBM *db,
                 datum key, datum content, int store_mode);

#endif // LIBDC_POSIX_DC_NDBM_H
