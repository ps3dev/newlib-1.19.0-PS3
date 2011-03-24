#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

#include <sys/reent.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <sys/resource.h>
#include <utime.h>

typedef struct _sys_lwmutex sys_lwmutex_t;
typedef struct _sys_lwmutex_attr sys_lwmutex_attr_t;

struct __syscalls_t {
	caddr_t (*sbrk_r)(struct _reent *r,ptrdiff_t incr);
	int (*close_r)(struct _reent *r,int fd);
	int (*open_r)(struct _reent *r,const char *file,int flags,int mode);
	_ssize_t (*read_r)(struct _reent *r,int fd,void *ptr,size_t len);
	_ssize_t (*write_r)(struct _reent *r,int fd,const void *ptr,size_t len);
	_off_t (*lseek_r)(struct _reent *r,int fd,_off_t pos,int dir);
	_off64_t (*lseek64_r)(struct _reent *r,int fd,_off64_t pos,int dir);
	int (*fstat_r)(struct _reent *r,int fd,struct stat *st);
	int (*fstat64_r)(struct _reent *r,int fd,struct stat *st);
	int (*stat_r)(struct _reent *r,const char *path,struct stat *st);
	int (*stat64_r)(struct _reent *r,const char *path,struct stat *st);
	int (*ftruncate_r)(struct _reent *r,int fd,off_t len);
	int (*truncate_r)(struct _reent *r,const char *path,off_t len);
	int (*fsync_r)(struct _reent *r,int fd);
	int (*link_r)(struct _reent *r,const char *old,const char *new);
	int (*unlink_r)(struct _reent *r,const char *name);
	int (*chmod_r)(struct _reent *r,const char *path,mode_t mode);
	int (*rename_r)(struct _reent *r,const char *old,const char *new);
	int (*utime_r)(struct _reent *r,const char *path,const struct utimbuf *times);

	mode_t (*umask_r)(struct _reent *r,mode_t cmask);

	int (*mkdir_r)(struct _reent *r,const char *path,mode_t mode);
	int (*rmdir_r)(struct _reent *r,const char *dirname);
	int (*chdir_r)(struct _reent *r,const char *dirname);
	char* (*getcwd_r)(struct _reent *r,char *buf,size_t size);

	int (*closedir_r)(struct _reent *r,DIR *dirp);
	DIR* (*opendir_r)(struct _reent *r,const char *dirname);
	struct dirent* (*readdir_r)(struct _reent *r,DIR *dirp);
	int (*readdir_r_r)(struct _reent *r,DIR *dirp,struct dirent *entry,struct dirent **result);
	void (*rewinddir_r)(struct _reent *r,DIR *dirp);
	void (*seekdir_r)(struct _reent *r,DIR *dirp,long int loc);
	long int (*telldir_r)(struct _reent *r,DIR *dirp);

	int (*getpid_r)(struct _reent *r);
	int (*isatty_r)(struct _reent *r,int fd);
	int (*execve_r)(struct _reent *r,char *name,char **argv,char **env);
	int (*gettod_r)(struct _reent *r,struct timeval *ptimeval,void *ptimezone);
	int (*settod_r)(struct _reent *r,const struct timeval *ptimeval,const struct timezone *ptimezone);
	int (*usleep_r)(struct _reent *r,useconds_t usec);
	int (*getrusage_r)(struct _reent *r,int who,struct rusage *r_usage);
	unsigned int (*sleep_r)(struct _reent *r,unsigned int sec);
	clock_t (*times_r)(struct _reent *r,struct tms *buf);

	int (*sys_lwmutex_create_r)(struct _reent *r,sys_lwmutex_t *lwmutex,const sys_lwmutex_attr_t *attr);
	int (*sys_lwmutex_destroy_r)(struct _reent *r,sys_lwmutex_t *lwmutex);
	int (*sys_lwmutex_lock_r)(struct _reent *r,sys_lwmutex_t *lwmutex,unsigned long long timeout);
	int (*sys_lwmutex_trylock_r)(struct _reent *r,sys_lwmutex_t *lwmutex);
	int (*sys_lwmutex_unlock_r)(struct _reent *r,sys_lwmutex_t *lwmutex);

	void (*exit)(int rc);
};

extern struct __syscalls_t __syscalls;

#endif
