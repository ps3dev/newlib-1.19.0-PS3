#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_link_r,(r,old,new),
	   struct _reent *r _AND
	   const char *old _AND
	   const char *new) {
#else
int
_DEFUN(_link(old,new),
	   const char *old _AND
	   const char *new) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.link_r)
		return __syscalls.link_r(r,old,new);

	r->_errno = ENOSYS;
	return -1;
}
