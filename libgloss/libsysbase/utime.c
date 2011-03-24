#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <reent.h>
#include <errno.h>
#include <utime.h>
#include <sys/syscalls.h>

int utime(const char *path,const struct utimbuf *times)
{
  struct _reent *r = _REENT;

  if(__syscalls.utime_r)
    return __syscalls.utime_r(r,path,times);

  r->_errno = ENOSYS;
  return -1;
}
