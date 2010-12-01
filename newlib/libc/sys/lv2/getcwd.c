//
// getcwd.c
// by Dan Peori (dan.peori@oopo.net)
//

#include <stdlib.h>
#include <errno.h>

char *getcwd ( char *buffer, size_t size )
{
  errno = ENOSYS;
  return NULL;
}
