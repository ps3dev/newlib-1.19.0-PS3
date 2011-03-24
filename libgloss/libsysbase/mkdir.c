#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscalls.h>

int
_DEFUN(mkdir,(path,mode),
	   const char *path _AND
	   mode_t mode)
{
	struct _reent *r = _REENT;

	if(__syscalls.mkdir_r)
		return __syscalls.mkdir_r(r,path,mode);

	r->_errno = ENOSYS;
	return -1;
}
