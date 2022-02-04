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

#include "dc_stdlib.h"
#include "dc_string.h"
#include <errno.h>
#include <unistd.h>

void dc__Exit(const struct dc_posix_env *env, int status)
{
    DC_TRACE(env);
    errno = 0;
    _Exit(status);
}

long dc_a64l(const struct dc_posix_env *env, struct dc_error *err, const char *s)
{
    long ret_val;

    DC_TRACE(env);
    errno = 0;

    if(s == NULL)
    {
        DC_ERROR_RAISE_SYSTEM(err, "dc_a64l: s cannot be null", 1);
        ret_val = 0;
    }
    else
    {
        ret_val = a64l(s);
    }

    return ret_val;
}

_Noreturn void dc_abort(const struct dc_posix_env *env)
{
    DC_TRACE(env);
    errno = 0;
    abort();
}

int dc_abs(const struct dc_posix_env *env, __attribute__((unused)) struct dc_error *err, int i)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;

    // TODO: handle if INT_MIN not working
    ret_val = abs(i);

    return ret_val;
}

int dc_atexit(const struct dc_posix_env *env, struct dc_error *err, void (*func)(void))
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;

    ret_val = atexit(func);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void *dc_bsearch(const struct dc_posix_env *env,
                 const void                *key,
                 const void                *base,
                 size_t                     nel,
                 size_t                     width,
                 int (*compar)(const void *, const void *))
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = bsearch(key, base, nel, width, compar);

    return ret_val;
}

void *dc_calloc(const struct dc_posix_env *env, struct dc_error *err, size_t nelem, size_t elsize)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = calloc(nelem, elsize);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
div_t                  dc_div(const struct dc_posix_env *env, int numer, int denom)
{
    div_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = div(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

double                 dc_drand48(const struct dc_posix_env *env)
{
    double ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = drand48();

    return ret_val;
}

double dc_erand48(const struct dc_posix_env *env, unsigned short xsubi[3])
{
    double ret_val;
    DC_TRACE(env);
    errno   = 0;
    ret_val = erand48(xsubi);

    return ret_val;
}

_Noreturn void dc_exit(const struct dc_posix_env *env, int status)
{
    DC_TRACE(env);
    errno = 0;
    exit(status);
}

void dc_free(const struct dc_posix_env *env, void *ptr, size_t size)
{
    DC_TRACE(env);

    if(env->zero_free)
    {
        dc_memset(env, ptr, 0, size);
    }

    free(ptr);
}

char *dc_getenv(const struct dc_posix_env *env, const char *name)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getenv(name);

    return ret_val;
}

int dc_getsubopt(const struct dc_posix_env *env, char **optionp, char * const *keylistp, char **valuep)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getsubopt(optionp, keylistp, valuep);

    return ret_val;
}

int dc_grantpt(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = grantpt(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_initstate(const struct dc_posix_env *env, unsigned seed, char *state, size_t size)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = initstate(seed, state, size);

    return ret_val;
}

long dc_jrand48(const struct dc_posix_env *env, unsigned short xsubi[3])
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = jrand48(xsubi);

    return ret_val;
}

char *dc_l64a(const struct dc_posix_env *env, long value)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = l64a(value);

    return ret_val;
}

long dc_labs(const struct dc_posix_env *env, __attribute__((unused)) struct dc_error *err, long i)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = labs(i);

    // TODO: handle the case that i can't be handled

    return ret_val;
}

void dc_lcong48(const struct dc_posix_env *env, unsigned short param[7])
{
    DC_TRACE(env);
    errno = 0;
    lcong48(param);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
ldiv_t                 dc_ldiv(const struct dc_posix_env *env, long numer, long denom)
{
    ldiv_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ldiv(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

long long dc_llabs(const struct dc_posix_env *env, __attribute__((unused)) struct dc_error *err, long long i)
{
    long long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = llabs(i);

    // TODO: handle if i cannot be represented

    return ret_val;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
lldiv_t                dc_lldiv(const struct dc_posix_env *env, long long numer, long long denom)
{
    lldiv_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lldiv(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

long                   dc_lrand48(const struct dc_posix_env *env)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lrand48();

    return ret_val;
}

void *dc_malloc(const struct dc_posix_env *env, struct dc_error *err, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = malloc(size);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

int dc_mblen(const struct dc_posix_env *env, struct dc_error *err, const char *s, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mblen(s, n);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_mbstowcs(const struct dc_posix_env *env,
                   struct dc_error           *err,
                   wchar_t * restrict pwcs,
                   const char * restrict s,
                   size_t n)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mbstowcs(pwcs, s, n);

    if(ret_val == (size_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_mbtowc(const struct dc_posix_env *env,
              struct dc_error           *err,
              wchar_t * restrict pwc,
              const char * restrict s,
              size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mbtowc(pwc, s, n);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_mkdtemp(const struct dc_posix_env *env, struct dc_error *err, char *template)
{
    void *dir;

    DC_TRACE(env);
    errno = 0;
    dir   = mkdtemp(template);

    if(dir == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return dir;
}

int dc_mkstemp(const struct dc_posix_env *env, struct dc_error *err, char *template)
{
    int fd;

    DC_TRACE(env);
    errno = 0;
    fd    = mkstemp(template);

    if(fd == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return fd;
}

long dc_mrand48(const struct dc_posix_env *env)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mrand48();

    return ret_val;
}

long dc_nrand48(const struct dc_posix_env *env, unsigned short xsubi[3])
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = nrand48(xsubi);

    return ret_val;
}

int dc_posix_memalign(const struct dc_posix_env *env,
                      struct dc_error           *err,
                      void                     **memptr,
                      size_t                     alignment,
                      size_t                     size)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = posix_memalign(memptr, alignment, size);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_posix_openpt(const struct dc_posix_env *env, struct dc_error *err, int oflag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = posix_openpt(oflag);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_ptsname(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ptsname(fildes);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putenv(const struct dc_posix_env *env, struct dc_error *err, char *string)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = putenv(string);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_qsort(const struct dc_posix_env *env,
              void                      *base,
              size_t                     nel,
              size_t                     width,
              int (*compar)(const void *, const void *))
{
    DC_TRACE(env);
    errno = 0;
    qsort(base, nel, width, compar);
}

int dc_rand(const struct dc_posix_env *env)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = rand();

    return ret_val;
}

long dc_random(const struct dc_posix_env *env)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = random();

    return ret_val;
}

void *dc_realloc(const struct dc_posix_env *env, struct dc_error *err, void *ptr, size_t size)
{
    void *memory;

    DC_TRACE(env);
    errno  = 0;
    memory = realloc(ptr, size);

    if(memory == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

char *dc_realpath(const struct dc_posix_env *env,
                  struct dc_error           *err,
                  const char * restrict file_name,
                  char * restrict resolved_name)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = realpath(file_name, resolved_name);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned short *dc_seed48(const struct dc_posix_env *env, unsigned short seed16v[3])
{
    unsigned short *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = seed48(seed16v);

    return ret_val;
}

int dc_setenv(const struct dc_posix_env *env,
              struct dc_error           *err,
              const char                *envname,
              const char                *envval,
              int                        overwrite)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setenv(envname, envval, overwrite);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_setstate(const struct dc_posix_env *env, char *state)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setstate(state);

    return ret_val;
}

void dc_srand(const struct dc_posix_env *env, unsigned seed)
{
    DC_TRACE(env);
    errno = 0;
    srand(seed);
}

void dc_srand48(const struct dc_posix_env *env, long seedval)
{
    DC_TRACE(env);
    errno = 0;
    srand48(seedval);
}

void dc_srandom(const struct dc_posix_env *env, unsigned seed)
{
    DC_TRACE(env);
    errno = 0;
    srandom(seed);
}

double
dc_strtod(const struct dc_posix_env *env, struct dc_error *err, const char * restrict nptr, char ** restrict endptr)
{
    double ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtod(nptr, endptr);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float dc_strtof(const struct dc_posix_env *env,
                struct dc_error           *err,
                const char * restrict nptr,
                char ** restrict endptr)
{
    float ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtof(nptr, endptr);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long dc_strtol(const struct dc_posix_env *env,
               struct dc_error           *err,
               const char * restrict nptr,
               char ** restrict endptr,
               int base)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtol(nptr, endptr, base);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double
dc_strtold(const struct dc_posix_env *env, struct dc_error *err, const char * restrict nptr, char ** restrict endptr)
{
    long double ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtold(nptr, endptr);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long dc_strtoll(const struct dc_posix_env *env,
                     struct dc_error           *err,
                     const char * restrict nptr,
                     char ** restrict endptr,
                     int base)
{
    long long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtoll(nptr, endptr, base);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long dc_strtoul(const struct dc_posix_env *env,
                         struct dc_error           *err,
                         const char * restrict str,
                         char ** restrict endptr,
                         int base)
{
    unsigned long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtoul(str, endptr, base);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long long dc_strtoull(const struct dc_posix_env *env,
                               struct dc_error           *err,
                               const char * restrict str,
                               char ** restrict endptr,
                               int base)
{
    unsigned long long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtoull(str, endptr, base);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_system(const struct dc_posix_env *env, struct dc_error *err, const char *command)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = system(command);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_unlockpt(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = unlockpt(fildes);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_unsetenv(const struct dc_posix_env *env, struct dc_error *err, const char *name)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = unsetenv(name);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_wcstombs(const struct dc_posix_env *env,
                   struct dc_error           *err,
                   char * restrict s,
                   const wchar_t * restrict pwcs,
                   size_t n)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = wcstombs(s, pwcs, n);

    if(ret_val == (size_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_wctomb(const struct dc_posix_env *env, struct dc_error *err, char *s, wchar_t wchar)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = wctomb(s, wchar);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
