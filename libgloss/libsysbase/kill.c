#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_kill_r,(r,pid,sig),
	   struct _reent *r _AND
	   int pid _AND
	   int sig) {
#else
int
_DEFUN(_kill(pid,sig),
	   int pid _AND
	   int sig) {
	struct _reent *r = _REENT;
#endif
	r->_errno = ENOSYS;
	return -1;
}
