#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

#include <sys/reent.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct _sys_lwmutex sys_lwmutex_t;
typedef struct _sys_lwmutex_attr sys_lwmutex_attr_t;

struct __syscalls_t {
	caddr_t (*sbrk_r)(struct _reent *r,ptrdiff_t incr);
	int (*close_r)(struct _reent *r,int fd);
	int (*open_r)(struct _reent *r,const char *file,int flags,int mode);
	_ssize_t (*read_r)(struct _reent *r,int fd,void *ptr,size_t len);
	_ssize_t (*write_r)(struct _reent *r,int fd,const void *ptr,size_t len);
	_off_t (*lseek_r)(struct _reent *r,int fd,_off_t pos,int dir);
	int (*fstat_r)(struct _reent *r,int fd,struct stat *st);
	int (*ftruncate_r)(struct _reent *r,int fd,off_t len);
	int (*fsync_r)(struct _reent *r,int fd);
	int (*unlink_r)(struct _reent *r,const char *name);
	int (*chmod_r)(struct _reent *r,const char *path,mode_t mode);

	int (*execve_r)(struct _reent *r,char *name,char **argv,char **env);
	int (*gettod_r)(struct _reent *r,struct timeval *ptimeval,void *ptimezone);

	int (*sys_lwmutex_create_r)(struct _reent *r,sys_lwmutex_t *lwmutex,const sys_lwmutex_attr_t *attr);
	int (*sys_lwmutex_destroy_r)(struct _reent *r,sys_lwmutex_t *lwmutex);
	int (*sys_lwmutex_lock_r)(struct _reent *r,sys_lwmutex_t *lwmutex,unsigned long long timeout);
	int (*sys_lwmutex_trylock_r)(struct _reent *r,sys_lwmutex_t *lwmutex);
	int (*sys_lwmutex_unlock_r)(struct _reent *r,sys_lwmutex_t *lwmutex);

	void (*exit)(int rc);
};

extern struct __syscalls_t __syscalls;

#endif
