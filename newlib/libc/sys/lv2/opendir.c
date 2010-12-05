#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "lv2syscall.h"

/*
 * open a directory.
 */
DIR *
opendir(const char *name)
{
  int32_t fd, r;
  DIR *dirp;

  if ((dirp = (DIR *)malloc(sizeof(DIR)+sizeof(struct dirent))) == NULL) {
    errno = ENOMEM;
    return NULL;
  }

  if ((r = __lv2syscall2(805, (uint64_t)name, (uint64_t)(void *)&fd)) != 0) {
    __lv2errno(r);
    free(dirp);
    return NULL;
  }

  dirp->dd_fd = fd;

  return dirp;
}
