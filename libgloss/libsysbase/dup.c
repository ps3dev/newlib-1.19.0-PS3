//
// dup.c
// by Dan Peori (dan.peori@oopo.net)
//

#include <errno.h>

int dup ( int old_handle )
{
  errno = ENOSYS;
  return -1;
}
