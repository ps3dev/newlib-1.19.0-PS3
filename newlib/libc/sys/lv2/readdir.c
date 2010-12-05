#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "lv2syscall.h"

/*
 * get next entry in a directory.
 */
struct dirent *
readdir(DIR *dirp)
{
  int32_t r;
  uint64_t rsize = 0;
  struct dirent *dp = (struct dirent *)dirp->dd_buf;
  if ((r = __lv2syscall3(806, __dirfd(dirp), (uint64_t)(void *)dp,
			 (uint64_t)(void *)&rsize)) != 0) {
    __lv2errno(r);
    return NULL;
  }
  return rsize? dp : NULL;
}
