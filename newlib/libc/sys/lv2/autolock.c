//
// autolock.c
// by Marcus Comstedt <marcus@mc.pp.se>
//

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock-internal.h"

/* The newlib codebase contains 7 pre-initialized mutices.
   Among them is the malloc mutex.  Thus, we keep a pool
   of 8 mutices which can be allocated without using malloc.  */

#define NUM_PREALLOCATED_MUTICES 8


static sys_lwmutex_t metaLock = { 0, };

static sys_lwmutex_t mutexPool[NUM_PREALLOCATED_MUTICES];
static int nextMutexIndex = 0;

void __libc_auto_lock_allocate(void **pMutex)
{
  if (!metaLock.attribute) {
    /* FIXME: There is a potential race condition here... */
    sys_lwmutex_create(&metaLock, &__libc_lock_attributes);
  }
  sys_lwmutex_lock(&metaLock, 0);

  /* Need to check the magic again now that we have the lock... */
  if (*pMutex == __libc_autolock_magic) {

    if (nextMutexIndex >= NUM_PREALLOCATED_MUTICES) {
      /* Out of mutices!? */
      *pMutex = NULL;
    } else {
      *pMutex = &mutexPool[nextMutexIndex++];
      sys_lwmutex_create(*pMutex, &__libc_lock_attributes);
    }

  }

  sys_lwmutex_unlock(&metaLock);
}

