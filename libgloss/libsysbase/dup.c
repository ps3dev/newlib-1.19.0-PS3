#include <errno.h>
#include <fcntl.h>
#include <reent.h>

int dup(int filedes)
{
	struct _reent *r = _REENT;
	r->_errno = ENOSYS;
	//return fcntl(filedes,F_DUPFD,0);
  return -1;
}
