#ifndef LIBDC_POSIX_POSIX_ENV_H
#define LIBDC_POSIX_POSIX_ENV_H


#include <stddef.h>
#include <stdbool.h>
#include <errno.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
struct dc_posix_env
{
    bool zero_malloc;
    bool zero_free;
    bool null_free;
    void (*error_reporter)(const char *file_name, const char *function_name, size_t line_number, int err);
    void (*tracer)(const char *file_name, const char *function_name, size_t line_number);
};
#pragma GCC diagnostic pop


void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const char *file_name, const char *function_name, size_t line_number, int err));


#define DC_REPORT_ERROR(env, err) if((env)->error_reporter) (env)->error_reporter(__FILE__, __func__, __LINE__, err)
#define DC_TRACE(env) if((env)->tracer) (env)->tracer(__FILE__, __func__, __LINE__)


#endif // LIBDC_POSIX_POSIX_ENV_H
