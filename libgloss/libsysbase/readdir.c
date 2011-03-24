#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

struct dirent*
_DEFUN(readdir,(dirp),
	   DIR *dirp)
{
	struct _reent *r = _REENT;

	if(__syscalls.readdir_r)
		return __syscalls.readdir_r(r,dirp);

	r->_errno = ENOSYS;
	return NULL;
}
