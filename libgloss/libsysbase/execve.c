#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_execve_r,(r,name,argv,env),
	   struct _reent *r _AND
	   char *name _AND
	   char **argv _AND
	   char **env) {
#else
int
_DEFUN(_execve,(name,argv,env),
	   char *name _AND
	   char **argv _AND
	   char **env) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.execve_r)
		return __syscalls.execve_r(r,name,argv,env);

	r->_errno = ENOSYS;
	return -1;
}
