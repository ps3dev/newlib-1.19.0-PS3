#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscalls.h>

mode_t umask(mode_t cmask)
{
	struct _reent *r = _REENT;

	if(__syscalls.umask_r)
		return __syscalls.umask_r(r,cmask);

	r->_errno = ENOSYS;
	return -1;
}
