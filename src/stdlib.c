#include "stdlib.h"
#include <stdlib.h>
#include <errno.h>


void *dc_malloc(const struct dc_posix_env *env, int *err, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno = 0;

    if(env->zero_malloc)
    {
        memory = calloc(1, size);
    }
    else
    {
        memory = malloc(size);
    }

    *err = errno;

    if(memory == NULL)
    {
        DC_REPORT_ERROR(env, errno);
    }

    return memory;
}

void dc_free(const struct dc_posix_env *env, void *ptr)
{
    DC_TRACE(env);
    free(ptr);
}
