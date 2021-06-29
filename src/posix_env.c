#include <string.h>
#include "posix_env.h"


void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const char *file_name, const char *function_name, size_t line_number, int err))
{
    memset(env, 0, sizeof(struct dc_posix_env));
    env->error_reporter = error_reporter;
}
