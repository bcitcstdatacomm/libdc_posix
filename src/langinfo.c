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

#include "dc_langinfo.h"

char *dc_nl_langinfo(const struct dc_posix_env *env, nl_item item)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nl_langinfo(item);

    return ret_val;
}

char *dc_nl_langinfo_l(const struct dc_posix_env *env, nl_item item, locale_t locale)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nl_langinfo_l(item, locale);

    return ret_val;
}
