#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
clock_t
_DEFUN(_times_r,(r,buf),
	   struct _reent *r _AND
	   struct tms *buf) {
#else
clock_t
_DEFUN(_times,(buf),
	   struct tms *buf) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.times_r)
		return __syscalls.times_r(r,buf);

	r->_errno = ENOSYS;
	return -1;
}
