#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock_internal.h"

int __libc_lock_init(__libc_lock_t *lock)
{
	return sys_lwmutex_create(lock,&__libc_lock_attributes);
}

int __libc_lock_close(__libc_lock_t *lock)
{
  return sys_lwmutex_destroy(lock);
}

int __libc_lock_acquire(__libc_lock_t *lock)
{
	if(SYS_LWMUTEX_UNINITIALIZED(lock))
    __libc_auto_lock_allocate(lock);
	return  sys_lwmutex_lock(lock,0);
}

int __libc_lock_try_acquire(__libc_lock_t *lock)
{
	if(SYS_LWMUTEX_UNINITIALIZED(lock))
    __libc_auto_lock_allocate(lock);
  return sys_lwmutex_trylock(lock);
}

int __libc_lock_release(__libc_lock_t *lock)
{
	if(SYS_LWMUTEX_UNINITIALIZED(lock))
    __libc_auto_lock_allocate(lock);
  return sys_lwmutex_unlock(lock);
}
