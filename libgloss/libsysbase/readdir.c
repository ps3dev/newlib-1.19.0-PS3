#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

struct dirent* readdir(DIR* dir)
{
	struct _reent *r = _REENT;
	if(__syscalls.readdir_r)
		return __syscalls.readdir_r(r,dir);

	r->_errno = ENOSYS;
	return NULL;
}
