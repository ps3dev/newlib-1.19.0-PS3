//
// lock.c
// by Marcus Comstedt <marcus@mc.pp.se>
//

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock-internal.h"

int __libc_lock_init(__libc_lock_t *lock)
{
  lock->lock = calloc(1, sizeof(sys_lwmutex_t));
  sys_lwmutex_create(lock->lock, &__libc_lock_attributes);
  return 0;
}

int __libc_lock_close(__libc_lock_t *lock)
{
  if (lock->lock) {
    sys_lwmutex_destroy(lock->lock);
    free(lock->lock);
    lock->lock = NULL;
  }
  return 0;
}

int __libc_lock_acquire(__libc_lock_t *lock)
{
  if (lock->lock == __libc_autolock_magic)
    __libc_auto_lock_allocate(&lock->lock);
  return sys_lwmutex_lock(lock->lock, 0);
}

int __libc_lock_try_acquire(__libc_lock_t *lock)
{
  if (lock->lock == __libc_autolock_magic)
    __libc_auto_lock_allocate(&lock->lock);
  /* Maybe there exists a real sys_lwmutex_trylock? */
  return sys_lwmutex_lock(lock->lock, 1);
}

int __libc_lock_release(__libc_lock_t *lock)
{
  if (lock->lock == __libc_autolock_magic)
    __libc_auto_lock_allocate(&lock->lock);
  return sys_lwmutex_unlock(lock->lock);
}

