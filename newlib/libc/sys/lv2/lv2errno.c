#include <stdint.h>
#include <errno.h>

static inline int maplv2errno(uint32_t errcode)
{
  switch(errcode) {
  case 0x8001002a:
    return EBADF;
  case 0x8001002e:
    return ENOTDIR;
  case 0x8001003a:
    return ENOENT;

    /**/
  }
  return EINVAL;
}

extern void __lv2errno(int32_t errcode)
{
  errno = maplv2errno((uint32_t)errcode);
}

