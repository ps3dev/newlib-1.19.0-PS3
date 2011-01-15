#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

int readdir_r(DIR* dir, struct dirent* entry, struct dirent** result)
{
	struct _reent *r = _REENT;
	if(__syscalls.readdir_r_r)
		return __syscalls.readdir_r_r(r,dir,entry,result);

	r->_errno = ENOSYS;
	return -1;
}
