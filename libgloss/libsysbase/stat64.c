#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_stat64_r,(r,path,st),
	   struct _reent *r _AND
	   const char *path _AND
	   struct stat *st) {
#else
int
_DEFUN(_stat64,(path,st),
	   const char *path _AND
	   struct stat *st) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.stat64_r)
		return __syscalls.stat64_r(r,path,st);

	r->_errno = ENOSYS;
	return -1;
}
