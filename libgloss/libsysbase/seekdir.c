#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

void 
_DEFUN(seekdir,(dirp,off),
	   DIR *dirp _AND
	   long int off)
{
	struct _reent *r = _REENT;

	if(__syscalls.seekdir_r)
		__syscalls.seekdir_r(r,dirp,off);
	else
		r->_errno = ENOSYS;
}
