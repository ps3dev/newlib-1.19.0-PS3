#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>


#ifdef REENTRANT_SYSCALLS_PROVIDED
int
_DEFUN(_isatty_r,(ptr,fd),
	   struct _reent *ptr _AND
		   int fd) {
#else
int
_DEFUN(isatty,(fd),
	   int fd) {
	struct _reent *ptr = _REENT;
#endif
	if(fd==stdout->_file || fd==stdin->_file || fd==stderr->_file)
		return 1;

	ptr->_errno = ENOTTY;
	return 0;
}
