#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "lv2syscall.h"

/*
 * close a directory.
 */
int
closedir(DIR *dirp)
{
  int32_t fd, r;

  fd = dirp->dd_fd;
  dirp->dd_fd = -1;
  (void)free((void *)dirp);
  if ((r = __lv2syscall1(807, fd)) != 0) {
    __lv2errno(r);
    return -1;
  } else
    return 0;
}
