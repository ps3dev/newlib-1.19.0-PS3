#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_isatty_r,(ptr,fd),
	   struct _reent *ptr _AND
		   int fd) {
#else
int
_DEFUN(isatty,(fd),
	   int fd) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.isatty_r)
		return __syscalls.isatty_r(ptr,fd);

	ptr->_errno = ENOTTY;
	return 0;
}
