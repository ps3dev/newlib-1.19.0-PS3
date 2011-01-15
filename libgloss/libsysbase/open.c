#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <sys/syscalls.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_open_r,(r,file,flags,mode),
	   struct _reent *r _AND
		   const char *file _AND
		   int flags _AND
		   int mode) {
#else
int
_DEFUN(_open,(file,flags,mode),
	   const char *file _AND
	   int flags _AND
	   int mode) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.open_r)
		return __syscalls.open_r(r,file,flags,mode);

	r->_errno = ENOSYS;
	return -1;
}
