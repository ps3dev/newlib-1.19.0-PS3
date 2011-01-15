#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

long int telldir(DIR* dir)
{
	struct _reent *r = _REENT;
	if(__syscalls.telldir_r)
		return __syscalls.telldir_r(r,dir);

	r->_errno = ENOSYS;
	return -1;
}
