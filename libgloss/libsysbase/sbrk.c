#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
caddr_t
_DEFUN(_sbrk_r,(ptr,incr),
	   struct _reent *ptr _AND
	   ptrdiff_t incr) {
#else
caddr_t
_DEFUN(_sbrk,(incr),
	   ptrdiff_t incr) {
	struct _reent *ptr = _REENT;
#endif
	if(__syscalls.sbrk_r)
		return __syscalls.sbrk_r(ptr,incr);
	else {
		ptr->_errno = ENOMEM;
		return (caddr_t)-1;
	}
}
