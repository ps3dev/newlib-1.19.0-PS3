#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

void rewinddir(DIR* dir)
{
	struct _reent *r = _REENT;
	if(__syscalls.rewinddir_r)
		__syscalls.rewinddir_r(r,dir);
	else
		r->_errno = ENOSYS;
}
