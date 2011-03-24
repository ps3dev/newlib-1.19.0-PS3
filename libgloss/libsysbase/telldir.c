#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

long int 
_DEFUN(telldir,(dirp),
	   DIR *dirp)
{
	struct _reent *r = _REENT;

	if(__syscalls.telldir_r)
		return __syscalls.telldir_r(r,dirp);

	r->_errno = ENOSYS;
	return -1;
}
