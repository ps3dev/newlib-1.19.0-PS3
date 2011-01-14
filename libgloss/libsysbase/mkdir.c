#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>
#include <errno.h>
#include <reent.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_mkdir_r,(r,path,mode),
	   struct _reent *r _AND
	   const char *path _AND
	   int mode) {
#else
int
_DEFUN(_mkdir,(path,mode),
	   const char *path _AND
	   int mode) {
	struct _reent *r = REENT;
#endif
	if(__syscalls.mkdir_r)
		return __syscalls.mkdir_r(r,path,mode);

	r->_errno = ENOSYS;
	return -1;
}

int
_DEFUN(mkdir,(path,mode),
	   const char *path _AND
	   mode_t mode) {
#ifdef REENTRANT_SYSCALLS_PROVIDED
	struct _reent *r = _REENT;
	_mkdir_r(r,path,mode);
#else
	_mkdir(path,mode);
#endif
}
