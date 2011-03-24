#ifndef __SYS_LOCK_INTERNAL_H__
#define __SYS_LOCK_INTERNAL_H__

#include <stdint.h>

#define SYS_LWMUTEX_ATTR_PROTOCOL			0x0002
#define SYS_LWMUTEX_ATTR_RECURSIVE			0x0010

#define SYS_LWMUTEX_UNINITIALIZED(plwm)		(!((plwm)->attribute))

typedef struct _sys_lwmutex sys_lwmutex_t;

typedef struct _sys_lwmutex_attr
{
	uint32_t attr_protocol;
	uint32_t attr_recursive;
	char name[8];
}sys_lwmutex_attr_t;

static const sys_lwmutex_attr_t __libc_lock_attributes = {
	SYS_LWMUTEX_ATTR_PROTOCOL,SYS_LWMUTEX_ATTR_RECURSIVE,""
};

extern void __libc_auto_lock_allocate(sys_lwmutex_t *lwmutex);

extern int32_t sys_lwmutex_create(sys_lwmutex_t *lwmutex,const sys_lwmutex_attr_t *attr);
extern int32_t sys_lwmutex_destroy(sys_lwmutex_t *lwmutex);
extern int32_t sys_lwmutex_lock(sys_lwmutex_t *lwmutex, uint64_t timeout);
extern int32_t sys_lwmutex_trylock(sys_lwmutex_t *lwmutex);
extern int32_t sys_lwmutex_unlock(sys_lwmutex_t *lwmutex);

#endif
