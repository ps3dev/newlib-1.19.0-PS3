#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <sys/resource.h>
#include <errno.h>

int
_DEFUN(_getrusage,(who, usage),
	   int who _AND
	   struct rusage *usage) {
	struct _reent *r = _REENT;
	if(__syscalls.getrusage_r)
		return __syscalls.getrusage_r(r,who,usage);

	r->_errno = ENOSYS;
	return -1;
}

