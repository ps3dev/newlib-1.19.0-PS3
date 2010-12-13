#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/lock.h>
#include <sys/syscalls.h>

int32_t sys_lwmutex_create(sys_lwmutex_t *lwmutex,const sys_lwmutex_attr_t *attr)
{
	struct _reent *r = _REENT;

	if(__syscalls.sys_lwmutex_create_r)
		return __syscalls.sys_lwmutex_create_r(r,lwmutex,attr);
	
	r->_errno = ENOSYS;
	return -1;
}

int32_t sys_lwmutex_destroy(sys_lwmutex_t *lwmutex)
{
	struct _reent *r = _REENT;

	if(__syscalls.sys_lwmutex_destroy_r)
		return __syscalls.sys_lwmutex_destroy_r(r,lwmutex);
	
	r->_errno = ENOSYS;
	return -1;
}

int32_t sys_lwmutex_lock(sys_lwmutex_t *lwmutex, uint64_t timeout)
{
	struct _reent *r = _REENT;

	if(__syscalls.sys_lwmutex_lock_r)
		return __syscalls.sys_lwmutex_lock_r(r,lwmutex,timeout);
	
	r->_errno = ENOSYS;
	return -1;
}

int32_t sys_lwmutex_trylock(sys_lwmutex_t *lwmutex)
{
	struct _reent *r = _REENT;

	if(__syscalls.sys_lwmutex_trylock_r)
		return __syscalls.sys_lwmutex_trylock_r(r,lwmutex);
	
	r->_errno = ENOSYS;
	return -1;
}

int32_t sys_lwmutex_unlock(sys_lwmutex_t *lwmutex)
{
	struct _reent *r = _REENT;

	if(__syscalls.sys_lwmutex_unlock_r)
		return __syscalls.sys_lwmutex_unlock_r(r,lwmutex);
	
	r->_errno = ENOSYS;
	return -1;
}

