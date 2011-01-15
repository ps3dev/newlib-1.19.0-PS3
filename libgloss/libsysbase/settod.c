#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <errno.h>

/*#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_settimeofday_r,(r,ptimeval,ptimezone),
	   struct _reent *r _AND
	   const struct timeval *ptimeval _AND
	   const struct timezone *ptimezone) {
#else*/
int
_DEFUN(settimeofday,(ptimeval,ptimezone),
	   const struct timeval *ptimeval _AND
	   const struct timezone *ptimezone) {
	struct _reent *r = _REENT;
/*#endif*/
	if(__syscalls.settod_r)
		return __syscalls.settod_r(r,ptimeval,ptimezone);

	r->_errno = ENOSYS;
	return -1;
}
