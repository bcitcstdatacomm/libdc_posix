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

#include "dc_ndbm.h"

int dc_dbm_clearerr(const struct dc_posix_env *env, struct dc_error *err, DBM *db)
{
    int error_code;

    DC_TRACE(env);
    errno   = 0;

    // linux returns void, so no assignment possible
    dbm_clearerr(db);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm clearerr error", error_code);
    }

    // it is undefined, and linux return nothing (void)...
    return 0;
}

void dc_dbm_close(const struct dc_posix_env *env, struct dc_error *err, DBM *db)
{
    int error_code;

    DC_TRACE(env);
    errno = 0;
    dbm_close(db);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm close error", error_code);
    }
}

int dc_dbm_delete(const struct dc_posix_env *env, struct dc_error *err, DBM *db, datum key)
{
    int ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_delete(db, key);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm delete error", error_code);
    }

    return ret_val;
}

int dc_dbm_error(const struct dc_posix_env *env, struct dc_error *err, DBM *db)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_error(db);

    return ret_val;
}

datum dc_dbm_fetch(const struct dc_posix_env *env, struct dc_error *err, DBM *db, datum key)
{
    datum ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_fetch(db, key);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm fetch error", error_code);
    }

    return ret_val;
}

datum dc_dbm_firstkey(const struct dc_posix_env *env, struct dc_error *err, DBM *db)
{
    datum ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_firstkey(db);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm firstkey error", error_code);
    }

    return ret_val;
}

datum dc_dbm_nextkey(const struct dc_posix_env *env, struct dc_error *err, DBM *db)
{
    datum ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_nextkey(db);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm nextkey error", error_code);
    }

    return ret_val;
}

DBM *dc_dbm_open(const struct dc_posix_env *env,
                 struct dc_error *          err,
                 const char *               file,
                 int                        open_flags,
                 mode_t                     file_mode)
{
    DBM *ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_open(file, open_flags, file_mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm open error", -1);
    }

    return ret_val;
}

int dc_dbm_store(const struct dc_posix_env *env,
                 struct dc_error *          err,
                 DBM *                      db,
                 datum                      key,
                 datum                      content,
                 int                        store_mode)
{
    int ret_val;
    int error_code;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dbm_store(db, key, content, store_mode);
    error_code = dbm_error(db);

    if(error_code != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dbm store error", error_code);
    }

    return ret_val;
}
