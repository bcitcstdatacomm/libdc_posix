#include "wordexp.h"


int dc_wordexp(const struct dc_posix_env *env,
               int *err,
               const char *restrict words,
               wordexp_t *restrict pwordexp,
               int flags)
{
    DC_TRACE(env);

    *err = wordexp(words, pwordexp, flags);

    if(*err)
    {
        DC_REPORT_ERROR(env, *err);
    }

    return *err;
}
