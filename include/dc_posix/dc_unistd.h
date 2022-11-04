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


#include <dc_env/env.h>
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_access(const struct dc_env *env, struct dc_error *err, const char *path, int amode);
unsigned dc_alarm(const struct dc_env *env, unsigned seconds);
int dc_chdir(const struct dc_env *env, struct dc_error *err, const char *path);
int dc_chown(const struct dc_env *env, struct dc_error *err, const char *path, uid_t owner, gid_t group);
int dc_close(const struct dc_env *env, struct dc_error *err, int fildes);
size_t dc_confstr(const struct dc_env *env, struct dc_error *err, int name, char *buf, size_t len);
int dc_dup(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_dup2(const struct dc_env *env, struct dc_error *err, int fildes, int fildes2);
void dc__exit(const struct dc_env *env, int status);
int dc_execv(const struct dc_env *env, struct dc_error *err, const char *path, char *const argv[]);
int dc_execve(const struct dc_env *env, struct dc_error *err, const char *path, char *const argv[], char *const envp[]);
int dc_execvp(const struct dc_env *env, struct dc_error *err, const char *file, char *const argv[]);
int dc_faccessat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, int amode, int flag);
int dc_fchdir(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_fchown(const struct dc_env *env, struct dc_error *err, int fildes, uid_t owner, gid_t group);
int dc_fchownat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, uid_t owner, gid_t group, int flag);
int dc_fexecve(const struct dc_env *env, struct dc_error *err, int fd, char *const argv[], char *const envp[]);
pid_t dc_fork(const struct dc_env *env, struct dc_error *err);
long dc_fpathconf(const struct dc_env *env, struct dc_error *err, int fildes, int name);
int dc_ftruncate(const struct dc_env *env, struct dc_error *err, int fildes, off_t length);
char *dc_getcwd(const struct dc_env *env, struct dc_error *err, char *buf, size_t size);
gid_t dc_getegid(const struct dc_env *env);
uid_t dc_geteuid(const struct dc_env *env);
gid_t dc_getgid(const struct dc_env *env);
int dc_getgroups(const struct dc_env *env, struct dc_error *err, int gidsetsize, gid_t grouplist[]);
int dc_gethostname(const struct dc_env *env, struct dc_error *err, char *name, size_t namelen);
char *dc_getlogin(const struct dc_env *env, struct dc_error *err);
int dc_getlogin_r(const struct dc_env *env, struct dc_error *err, char *name, size_t namesize);
int dc_getopt(const struct dc_env *env, int argc, char * const argv[], const char *optstring);
pid_t dc_getpgid(const struct dc_env *env, struct dc_error *err, pid_t pid);
pid_t dc_getpgrp(const struct dc_env *env);
pid_t dc_getpid(const struct dc_env *env);
pid_t dc_getppid(const struct dc_env *env);
pid_t dc_getsid(const struct dc_env *env, struct dc_error *err, pid_t pid);
uid_t dc_getuid(const struct dc_env *env);
int dc_isatty(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_lchown(const struct dc_env *env, struct dc_error *err, const char *path, uid_t owner, gid_t group);
int dc_link(const struct dc_env *env, struct dc_error *err, const char *path1, const char *path2);
int dc_linkat(const struct dc_env *env, struct dc_error *err, int fd1, const char *path1, int fd2, const char *path2, int flag);
off_t dc_lseek(const struct dc_env *env, struct dc_error *err, int fildes, off_t offset, int whence);
long dc_pathconf(const struct dc_env *env, struct dc_error *err, const char *path, int name);
int dc_pause(const struct dc_env *env, struct dc_error *err);
int dc_pipe(const struct dc_env *env, struct dc_error *err, int fildes[2]);
ssize_t dc_pread(const struct dc_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte, off_t offset);
ssize_t dc_pwrite(const struct dc_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte, off_t offset);
ssize_t dc_read(const struct dc_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte);
ssize_t dc_readlink(const struct dc_env *env, struct dc_error *err, const char *restrict path, char *restrict buf, size_t bufsize);
ssize_t dc_readlinkat(const struct dc_env *env, struct dc_error *err, int fd, const char *restrict path, char *restrict buf, size_t bufsize);
int dc_rmdir(const struct dc_env *env, struct dc_error *err, const char *path);
int dc_setegid(const struct dc_env *env, struct dc_error *err, gid_t gid);
int dc_seteuid(const struct dc_env *env, struct dc_error *err, uid_t uid);
int dc_setgid(const struct dc_env *env, struct dc_error *err, gid_t gid);
int dc_setpgid(const struct dc_env *env, struct dc_error *err, pid_t pid, pid_t pgid);
pid_t dc_setsid(const struct dc_env *env, struct dc_error *err);
int dc_setuid(const struct dc_env *env, struct dc_error *err, uid_t uid);
unsigned dc_sleep(const struct dc_env *env, unsigned seconds);
int dc_symlink(const struct dc_env *env, struct dc_error *err, const char *path1, const char *path2);
int dc_symlinkat(const struct dc_env *env, struct dc_error *err, const char *path1, int fd, const char *path2);
long dc_sysconf(const struct dc_env *env, struct dc_error *err, int name);
pid_t dc_tcgetpgrp(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_tcsetpgrp(const struct dc_env *env, struct dc_error *err, int fildes, pid_t pgid_id);
int dc_truncate(const struct dc_env *env, struct dc_error *err, const char *path, off_t length);
char *dc_ttyname(const struct dc_env *env, struct dc_error *err, int fildes);
int dc_ttyname_r(const struct dc_env *env, struct dc_error *err, int fildes, char *name, size_t namesize);
int dc_unlink(const struct dc_env *env, struct dc_error *err, const char *path);
int dc_unlinkat(const struct dc_env *env, struct dc_error *err, int fd, const char *path, int flag);
ssize_t dc_write(const struct dc_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_UNISTD_H
