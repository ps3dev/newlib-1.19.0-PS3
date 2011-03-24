#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>

int
_DEFUN(settimeofday,(ptimeval,ptimezone),
	   const struct timeval *ptimeval _AND
	   const struct timezone *ptimezone)
{
	struct _reent *r = _REENT;

	if(__syscalls.settod_r)
		return __syscalls.settod_r(r,ptimeval,ptimezone);

	r->_errno = ENOSYS;
	return -1;
}
