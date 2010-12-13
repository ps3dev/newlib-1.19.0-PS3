#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
_off_t
_DEFUN(_lseek_r,(r,fd,pos,dir),
	   struct _reent *r _AND
		   int fd _AND
		   _off_t pos _AND
		   int dir) {
#else
_off_t
_DEFUN(_lseek,(fd,pos,dir),
	   int fd _AND
	   _off_t pos _AND
	   int dir) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.lseek_r)
		return __syscalls.lseek_r(r,fd,pos,dir);

	r->_errno = ENOSYS;
	return (_off_t)-1;
}
