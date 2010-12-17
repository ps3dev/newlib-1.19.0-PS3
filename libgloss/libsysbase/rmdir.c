#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>
#include <errno.h>

int rmdir(const char *dirname)
{
  struct _reent *r = _REENT;

  if(__syscalls.rmdir_r)
    return __syscalls.rmdir_r(r,dirname);

  r->_errno = ENOSYS;
  return -1;
}
