//
// glob.c
// by Dan Peori (dan.peori@oopo.net)
//

#include <glob.h>
#include <stdlib.h>
#include <errno.h>

int glob ( const char *pattern, int flags, int (*errfunc) ( const char *epath, int eerrno ), glob_t *pglob )
{
  if (errfunc != NULL)
    errfunc(NULL, ENOSYS);
  return 0;
}
