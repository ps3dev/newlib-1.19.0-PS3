#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_close_r,(ptr,fd),
	   struct _reent *ptr _AND
	   int fd) {
#else
int
_DEFUN(_close,(fd),
	   int fd) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.close_r)
		return __syscalls.close_r(ptr,fd);

	ptr->_errno = ENOSYS;
	return -1;
}
