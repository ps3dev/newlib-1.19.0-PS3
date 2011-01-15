#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

int closedir(DIR* dir)
{
	struct _reent *r = _REENT;
	if(__syscalls.closedir_r)
		return __syscalls.closedir_r(r,dir);

	r->_errno = ENOSYS;
	return -1;
}
