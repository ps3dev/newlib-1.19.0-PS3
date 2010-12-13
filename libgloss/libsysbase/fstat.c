#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_fstat_r,(r,fd,st),
	   struct _reent *r _AND
	   int fd _AND
	   struct stat *st) {
#else
int
_DEFUN(_fstat,(fd,st),
	   int fd _AND
	   struct stat *st) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.fstat_r)
		return __syscalls.fstat_r(r,fd,st);

	r->_errno = ENOSYS;
	return -1;
}
