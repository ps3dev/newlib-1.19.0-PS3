#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
_ssize_t
_DEFUN(_read_r,(r,fd,ptr,len),
	   struct _reent *r _AND
		   int fd _AND
		   void *ptr _AND
		   size_t len) {
#else
_ssize_t
_DEFUN(_read,(fd,ptr,len),
	   int fd _AND
	   void *ptr _AND
	   size_t len) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.read_r)
		return __syscalls.read_r(r,fd,ptr,len);

	r->_errno = ENOSYS;
	return -1;
}
