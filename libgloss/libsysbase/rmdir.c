#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

int
_DEFUN(rmdir,(dirname),
	   const char *dirname)
{
  struct _reent *r = _REENT;

  if(__syscalls.rmdir_r)
    return __syscalls.rmdir_r(r,dirname);

  r->_errno = ENOSYS;
  return -1;
}
