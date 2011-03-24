#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

int readdir_r(DIR *dirp,struct dirent *entry,struct dirent **result)
{
	struct _reent *r = _REENT;

	if(__syscalls.readdir_r_r)
		return __syscalls.readdir_r_r(r,dirp,entry,result);

	r->_errno = ENOSYS;
	return -1;
}
