#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>
#include <errno.h>

int 
_DEFUN(chmod,(path,mode),
	   const char *path _AND
	   mode_t mode)
{
	struct _reent *r = _REENT;

	if(__syscalls.chmod_r)
		return __syscalls.chmod_r(r,path,mode);

	r->_errno = ENOSYS;
	return -1;
}
