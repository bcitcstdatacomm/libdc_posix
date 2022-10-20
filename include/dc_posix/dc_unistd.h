#ifndef LIBDC_POSIX_DC_UNISTD_H
#define LIBDC_POSIX_DC_UNISTD_H


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
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 * @param path
 * @param amode
 * @return
 */
int dc_access(const struct dc_posix_env *env, struct dc_error *err,
              const char *path, int amode);

/**
 *
 * @param env
 * @param seconds
 * @return
 */
unsigned dc_alarm(const struct dc_posix_env *env, unsigned seconds);

/**
 *
 * @param env
 * @param err
 * @param path
 * @return
 */
int dc_chdir(const struct dc_posix_env *env, struct dc_error *err,
             const char *path);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param owner
 * @param group
 * @return
 */
int dc_chown(const struct dc_posix_env *env, struct dc_error *err,
             const char *path, uid_t owner, gid_t group);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_dc_close(const struct dc_posix_env *env, struct dc_error *err,
                int fildes);
int dc_close(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param buf
 * @param len
 * @return
 */
size_t dc_confstr(const struct dc_posix_env *env, struct dc_error *err,
                  int name, char *buf, size_t len);

/**
 *
 * @param env
 * @param err
 * @param key
 * @param salt
 * @return
 */
char *dc_crypt(const struct dc_posix_env *env, struct dc_error *err,
               const char *key, const char *salt);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_dup(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param fildes2
 * @return
 */
int dc_dup2(const struct dc_posix_env *env, struct dc_error *err, int fildes,
            int fildes2);

/*
 *
 * @param env
 * @param err
 * @param block
 * @param edflag
 */
// void dc_encrypt(const struct dc_posix_env *env, struct dc_error *err, char
// block[64], int edflag);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param argv
 * @return
 */
int dc_execv(const struct dc_posix_env *env, struct dc_error *err,
             const char *path, char *const argv[]);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param argv
 * @param envp
 * @return
 */
int dc_execve(const struct dc_posix_env *env, struct dc_error *err,
              const char *path, char *const argv[], char *const envp[]);

/**
 *
 * @param env
 * @param err
 * @param file
 * @param argv
 * @return
 */
int dc_execvp(const struct dc_posix_env *env, struct dc_error *err,
              const char *file, char *const argv[]);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param amode
 * @param flag
 * @return
 */
int dc_faccessat(const struct dc_posix_env *env, struct dc_error *err, int fd,
                 const char *path, int amode, int flag);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_fchdir(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param owner
 * @param group
 * @return
 */
int dc_fchown(const struct dc_posix_env *env, struct dc_error *err, int fildes,
              uid_t owner, gid_t group);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param owner
 * @param group
 * @param flag
 * @return
 */
int dc_fchownat(const struct dc_posix_env *env, struct dc_error *err, int fd,
                const char *path, uid_t owner, gid_t group, int flag);

// int dc_fdatasync(const struct dc_posix_env *env, int fildes);
// int dc_fexecve(const struct dc_posix_env *env, struct dc_error *err, int fd,
// char *const argv[], char *const envp[]);

/**
 *
 * @param env
 * @param err
 * @return
 */
pid_t dc_fork(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param name
 * @return
 */
long dc_fpathconf(const struct dc_posix_env *env, struct dc_error *err,
                  int fildes, int name);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_fsync(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param length
 * @return
 */
int dc_ftruncate(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes, off_t length);

/**
 *
 * @param env
 * @param err
 * @param buf
 * @param size
 * @return
 */
char *dc_getcwd(const struct dc_posix_env *env, struct dc_error *err, char *buf,
                size_t size);

/**
 *
 * @param env
 * @return
 */
gid_t dc_getegid(const struct dc_posix_env *env);
/**
 *
 * @param env
 * @return
 */
gid_t dc_geteuid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @return
 */
gid_t dc_getgid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param gidsetsize
 * @param grouplist
 * @return
 */
int dc_getgroups(const struct dc_posix_env *env, struct dc_error *err,
                 int gidsetsize, gid_t grouplist[]);

/**
 *
 * @param env
 * @return
 */
long dc_gethostid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param namelen
 * @return
 */
int dc_gethostname(const struct dc_posix_env *env, struct dc_error *err,
                   char *name, size_t namelen);

/**
 *
 * @param env
 * @param err
 * @return
 */
char *dc_getlogin(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param namesize
 * @return
 */
int dc_getlogin_r(const struct dc_posix_env *env, struct dc_error *err,
                  char *name, size_t namesize);

/**
 *
 * @param env
 * @param err
 * @param argc
 * @param argv
 * @param optstring
 * @return
 */
int dc_getopt(const struct dc_posix_env *env, struct dc_error *err, int argc,
              char *const argv[], const char *optstring);

/**
 *
 * @param env
 * @param err
 * @param pid
 * @return
 */
pid_t dc_getpgid(const struct dc_posix_env *env, struct dc_error *err,
                 pid_t pid);

/**
 *
 * @param env
 * @return
 */
pid_t dc_getpgrp(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @return
 */
pid_t dc_getpid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @return
 */
pid_t dc_getppid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param pid
 * @return
 */
pid_t dc_getsid(const struct dc_posix_env *env, struct dc_error *err,
                pid_t pid);

/**
 *
 * @param env
 * @return
 */
uid_t dc_getuid(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_isatty(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param owner
 * @param group
 * @return
 */
int dc_lchown(const struct dc_posix_env *env, struct dc_error *err,
              const char *path, uid_t owner, gid_t group);

/**
 *
 * @param env
 * @param err
 * @param path1
 * @param path2
 * @return
 */
int dc_link(const struct dc_posix_env *env, struct dc_error *err,
            const char *path1, const char *path2);

/**
 *
 * @param env
 * @param err
 * @param fd1
 * @param path1
 * @param fd2
 * @param path2
 * @param flag
 * @return
 */
int dc_linkat(const struct dc_posix_env *env, struct dc_error *err, int fd1,
              const char *path1, int fd2, const char *path2, int flag);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param function
 * @param size
 * @return
 */
int dc_lockf(const struct dc_posix_env *env, struct dc_error *err, int fildes,
             int function, off_t size);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param offset
 * @param whence
 * @return
 */
off_t dc_lseek(const struct dc_posix_env *env, struct dc_error *err, int fildes,
               off_t offset, int whence);

/**
 *
 * @param env
 * @param err
 * @param incr
 * @return
 */
int dc_nice(const struct dc_posix_env *env, struct dc_error *err, int incr);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param name
 * @return
 */
long dc_pathconf(const struct dc_posix_env *env, struct dc_error *err,
                 const char *path, int name);

/**
 *
 * @param env
 * @param err
 * @return
 */
int dc_pause(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_pipe(const struct dc_posix_env *env, struct dc_error *err,
            int fildes[2]);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @param offset
 * @return
 */
ssize_t dc_pread(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes, void *buf, size_t nbyte, off_t offset);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @param offset
 * @return
 */
ssize_t dc_pwrite(const struct dc_posix_env *env, struct dc_error *err,
                  int fildes, const void *buf, size_t nbyte, off_t offset);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @return
 */
ssize_t dc_read(const struct dc_posix_env *env, struct dc_error *err,
                int fildes, void *buf, size_t nbyte);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param buf
 * @param bufsize
 * @return
 */
ssize_t dc_readlink(const struct dc_posix_env *env, struct dc_error *err,
                    const char *restrict path, char *restrict buf,
                    size_t bufsize);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param buf
 * @param bufsize
 * @return
 */
ssize_t dc_readlinkat(const struct dc_posix_env *env, struct dc_error *err,
                      int fd, const char *restrict path, char *restrict buf,
                      size_t bufsize);

/**
 *
 * @param env
 * @param err
 * @param path
 * @return
 */
int dc_rmdir(const struct dc_posix_env *env, struct dc_error *err,
             const char *path);

/**
 *
 * @param env
 * @param err
 * @param gid
 * @return
 */
int dc_setegid(const struct dc_posix_env *env, struct dc_error *err, gid_t gid);

/**
 *
 * @param env
 * @param err
 * @param uid
 * @return
 */
int dc_seteuid(const struct dc_posix_env *env, struct dc_error *err, uid_t uid);

/**
 *
 * @param env
 * @param err
 * @param gid
 * @return
 */
int dc_setgid(const struct dc_posix_env *env, struct dc_error *err, gid_t gid);

/**
 *
 * @param env
 * @param err
 * @param pid
 * @param pgid
 * @return
 */
int dc_setpgid(const struct dc_posix_env *env, struct dc_error *err, pid_t pid,
               pid_t pgid);

/**
 *
 * @param env
 * @param err
 * @param rgid
 * @param egid
 * @return
 */
int dc_setregid(const struct dc_posix_env *env, struct dc_error *err,
                gid_t rgid, gid_t egid);

/**
 *
 * @param env
 * @param err
 * @param ruid
 * @param euid
 * @return
 */
int dc_setreuid(const struct dc_posix_env *env, struct dc_error *err,
                uid_t ruid, uid_t euid);

/**
 *
 * @param env
 * @param err
 * @return
 */
pid_t dc_setsid(const struct dc_posix_env *env, struct dc_error *err);

/**
 *
 * @param env
 * @param err
 * @param uid
 * @return
 */
int dc_setuid(const struct dc_posix_env *env, struct dc_error *err, uid_t uid);

/**
 *
 * @param env
 * @param seconds
 * @return
 */
unsigned dc_sleep(const struct dc_posix_env *env, unsigned seconds);

/**
 *
 * @param env
 * @param src
 * @param dest
 * @param nbytes
 */
void dc_swab(const struct dc_posix_env *env, const void *restrict src,
             void *restrict dest, ssize_t nbytes);

/**
 *
 * @param env
 * @param err
 * @param path1
 * @param path2
 * @return
 */
int dc_symlink(const struct dc_posix_env *env, struct dc_error *err,
               const char *path1, const char *path2);

/**
 *
 * @param env
 * @param err
 * @param path1
 * @param fd
 * @param path2
 * @return
 */
int dc_symlinkat(const struct dc_posix_env *env, struct dc_error *err,
                 const char *path1, int fd, const char *path2);

/**
 *
 * @param env
 */
void dc_sync(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param name
 * @return
 */
long dc_sysconf(const struct dc_posix_env *env, struct dc_error *err, int name);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
pid_t dc_tcgetpgrp(const struct dc_posix_env *env, struct dc_error *err,
                   int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param pgid_id
 * @return
 */
int dc_tcsetpgrp(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes, pid_t pgid_id);

/**
 *
 * @param env
 * @param err
 * @param path
 * @param length
 * @return
 */
int dc_truncate(const struct dc_posix_env *env, struct dc_error *err,
                const char *path, off_t length);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
char *dc_ttyname(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param name
 * @param namesize
 * @return
 */
int dc_ttyname_r(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes, char *name, size_t namesize);

/**
 *
 * @param env
 * @param err
 * @param path
 * @return
 */
int dc_unlink(const struct dc_posix_env *env, struct dc_error *err,
              const char *path);

/**
 *
 * @param env
 * @param err
 * @param fd
 * @param path
 * @param flag
 * @return
 */
int dc_unlinkat(const struct dc_posix_env *env, struct dc_error *err, int fd,
                const char *path, int flag);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param buf
 * @param nbyte
 * @return
 */
ssize_t dc_write(const struct dc_posix_env *env, struct dc_error *err,
                 int fildes, const void *buf, size_t nbyte);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_UNISTD_H
