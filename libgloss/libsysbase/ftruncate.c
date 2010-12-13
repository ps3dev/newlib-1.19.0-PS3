#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/syscalls.h>

int
_DEFUN(ftruncate,(fd,len),
	   int fd _AND
	   off_t len)
{
	struct _reent *r = _REENT;

	if(__syscalls.ftruncate_r)
		return __syscalls.ftruncate_r(r,fd,len);

	r->_errno = ENOSYS;
	return -1;
}
