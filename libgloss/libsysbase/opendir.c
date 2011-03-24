#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

DIR* opendir(const char *dir)
{
	struct _reent *r = _REENT;

	if(__syscalls.opendir_r)
		return __syscalls.opendir_r(r,dir);

	r->_errno = ENOSYS;
	return NULL;
}
