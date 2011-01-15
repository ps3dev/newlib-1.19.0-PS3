#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/syscalls.h>

void seekdir(DIR* dir, long int offset)
{
	struct _reent *r = _REENT;
	if(__syscalls.seekdir_r)
		__syscalls.seekdir_r(r,dir,offset);
	else
		r->_errno = ENOSYS;
}
