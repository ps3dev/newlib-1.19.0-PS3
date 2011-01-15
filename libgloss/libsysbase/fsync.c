#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/syscalls.h>

int
_DEFUN(fsync,(fd),
	   int fd)
{
	struct _reent *r = _REENT;

	if(__syscalls.fsync_r)
		return __syscalls.fsync_r(r,fd);

	r->_errno = ENOSYS;
	return -1;
}
