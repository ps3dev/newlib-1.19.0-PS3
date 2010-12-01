//
// getrusage.c
// by Dan Peori (dan.peori@oopo.net)
//

#include <sys/resource.h>
#include <errno.h>

int getrusage ( int who, struct rusage *r_usage )
{
  errno = ENOSYS;
  return -1;
}

