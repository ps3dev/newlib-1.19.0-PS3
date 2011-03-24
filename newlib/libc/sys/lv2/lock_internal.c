#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/lock.h>

#include "lock_internal.h"

static sys_lwmutex_t metaLock;

static void init_metalock(void) __attribute__((constructor(105)));
static void init_metalock(void)
{
	if(sys_lwmutex_create(&metaLock,&__libc_lock_attributes))
		abort();
}

void __libc_auto_lock_allocate(sys_lwmutex_t *lwmutex)
{
	if(sys_lwmutex_lock(&metaLock,0))
		abort();

	if(SYS_LWMUTEX_UNINITIALIZED(lwmutex)) {
		if(sys_lwmutex_create(lwmutex,&__libc_lock_attributes))
			abort();
	}

	if(sys_lwmutex_unlock(&metaLock))
		abort();
}
