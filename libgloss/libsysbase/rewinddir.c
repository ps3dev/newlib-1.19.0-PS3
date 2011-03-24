#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

void rewinddir(DIR *dirp)
{
	struct _reent *r = _REENT;

	if(__syscalls.rewinddir_r)
		__syscalls.rewinddir_r(r,dirp);
	else
		r->_errno = ENOSYS;
}
