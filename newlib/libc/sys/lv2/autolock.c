//
// autolock.c
// by Marcus Comstedt <marcus@mc.pp.se>
//

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock-internal.h"


static sys_lwmutex_t metaLock = { 0, };

void __libc_auto_lock_allocate(sys_lwmutex_t *pMutex)
{
  if (LWMUTEX_UNINITIALIZED(&metaLock)) {
    /* FIXME: There is a potential race condition here... */
    sys_lwmutex_create(&metaLock, &__libc_lock_attributes);
  }
  sys_lwmutex_lock(&metaLock, 0);

  /* Need to check the magic again now that we have the lock... */
  if (LWMUTEX_UNINITIALIZED(pMutex)) {

    sys_lwmutex_create(pMutex, &__libc_lock_attributes);

  }

  sys_lwmutex_unlock(&metaLock);
}

