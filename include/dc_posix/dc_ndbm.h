#ifndef LIBDC_POSIX_DC_NDBM_H
#define LIBDC_POSIX_DC_NDBM_H

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
#include <ndbm.h>
#include <sys/types.h>

/**
 *
 * @param env
 * @param err
 * @param db
 * @return
 */
int dc_dbm_clearerr(const struct dc_posix_env *env, struct dc_error *err,
                    DBM *db);

/**
 *
 * @param env
 * @param err
 * @param db
 */
void dc_dbm_close(const struct dc_posix_env *env, struct dc_error *err,
                  DBM *db);

/**
 *
 * @param env
 * @param err
 * @param db
 * @param key
 * @return
 */
int dc_dbm_delete(const struct dc_posix_env *env, struct dc_error *err, DBM *db,
                  datum key);

/**
 *
 * @param env
 * @param db
 * @return
 */
int dc_dbm_error(const struct dc_posix_env *env, DBM *db);

/**
 *
 * @param env
 * @param err
 * @param db
 * @param key
 * @return
 */
datum dc_dbm_fetch(const struct dc_posix_env *env, struct dc_error *err,
                   DBM *db, datum key);

/**
 *
 * @param env
 * @param err
 * @param db
 * @return
 */
datum dc_dbm_firstkey(const struct dc_posix_env *env, struct dc_error *err,
                      DBM *db);

/**
 *
 * @param env
 * @param err
 * @param db
 * @return
 */
datum dc_dbm_nextkey(const struct dc_posix_env *env, struct dc_error *err,
                     DBM *db);

/**
 *
 * @param env
 * @param err
 * @param file
 * @param open_flags
 * @param file_mode
 * @return
 */
DBM *dc_dbm_open(const struct dc_posix_env *env, struct dc_error *err,
                 const char *file, int open_flags, mode_t file_mode);

/**
 *
 * @param env
 * @param err
 * @param db
 * @param key
 * @param content
 * @param store_mode
 * @return
 */
int dc_dbm_store(const struct dc_posix_env *env, struct dc_error *err, DBM *db,
                 datum key, datum content, int store_mode);

#endif // LIBDC_POSIX_DC_NDBM_H
