#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
_ssize_t
_DEFUN(_write_r,(r,fd,ptr,len),
	   struct _reent *r _AND
		   int fd _AND
		   const void *ptr _AND
		   size_t len) {
#else
_ssize_t
_DEFUN(_write,(fd,ptr,len),
	   int fd _AND
	   const void *ptr _AND
	   size_t len) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.write_r)
		return __syscalls.write_r(r,fd,ptr,len);

	r->_errno = ENOSYS;
	return -1;
}
