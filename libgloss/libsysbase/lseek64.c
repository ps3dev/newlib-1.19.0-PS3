#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
_off64_t
_DEFUN(_lseek64_r,(r,fd,pos,dir),
	   struct _reent *r _AND
		   int fd _AND
		   _off64_t pos _AND
		   int dir) {
#else
_off64_t
_DEFUN(_lseek64,(fd,pos,dir),
	   int fd _AND
	   _off64_t pos _AND
	   int dir) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.lseek64_r)
		return __syscalls.lseek64_r(r,fd,pos,dir);

	r->_errno = ENOSYS;
	return -1;
}
