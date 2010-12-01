//
// autolock.c
// by Marcus Comstedt <marcus@mc.pp.se>
//

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock-internal.h"


static sys_lwmutex_t metaLock;

static void init_metalock(void) __attribute__((constructor(105)));
static void init_metalock(void)
{
  if (sys_lwmutex_create(&metaLock, &__libc_lock_attributes))
    abort();
}

void __libc_auto_lock_allocate(sys_lwmutex_t *pMutex)
{
  if (sys_lwmutex_lock(&metaLock, 0))
    abort();

  /* Need to check the magic again now that we have the lock... */
  if (LWMUTEX_UNINITIALIZED(pMutex)) {

    if(sys_lwmutex_create(pMutex, &__libc_lock_attributes))
      abort();

  }

  if (sys_lwmutex_unlock(&metaLock))
    abort();
}

