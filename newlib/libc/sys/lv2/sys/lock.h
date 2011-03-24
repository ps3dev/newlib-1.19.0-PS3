#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

#include <stdint.h>

struct _sys_lwmutex
{
  uint64_t lock_var;
  uint32_t attribute;
  uint32_t recursive_count;
  uint32_t sleep_queue;
	uint32_t _pad;
};

typedef struct _sys_lwmutex __libc_lock_t, __libc_lock_recursive_t;

#define __libc_lock_define_initialized(CLASS,NAME) CLASS __libc_lock_t NAME = {0,};
#define __libc_lock_define_initialized_recursive(CLASS,NAME) CLASS __libc_lock_recursive_t NAME = {0,};

int __libc_lock_init(__libc_lock_t *lock);
int __libc_lock_init_recursive(__libc_lock_recursive_t *lock);
int __libc_lock_close(__libc_lock_t *lock);
int __libc_lock_close_recursive(__libc_lock_recursive_t *lock);
int __libc_lock_acquire(__libc_lock_t *lock);
int __libc_lock_acquire_recursive(__libc_lock_recursive_t *lock);
int __libc_lock_try_acquire(__libc_lock_t *lock);
int __libc_lock_try_acquire_recursive(__libc_lock_recursive_t *lock);
int __libc_lock_release(__libc_lock_t *lock);
int __libc_lock_release_recursive(__libc_lock_recursive_t *lock);

typedef __libc_lock_t _LOCK_T;
typedef __libc_lock_recursive_t _LOCK_RECURSIVE_T;

#define __LOCK_INIT(CLASS, NAME) __libc_lock_define_initialized(CLASS, NAME)
#define __LOCK_INIT_RECURSIVE(CLASS, NAME) __libc_lock_define_initialized_recursive(CLASS, NAME)
#define __lock_init(NAME) __libc_lock_init(&(NAME))
#define __lock_init_recursive(NAME) __libc_lock_init_recursive(&(NAME))
#define __lock_close(NAME) __libc_lock_close(&(NAME))
#define __lock_close_recursive(NAME) __libc_lock_close_recursive(&(NAME))
#define __lock_acquire(NAME) __libc_lock_acquire(&(NAME))
#define __lock_acquire_recursive(NAME) __libc_lock_acquire_recursive(&(NAME))
#define __lock_try_acquire(NAME) __libc_lock_try_acquire(&(NAME))
#define __lock_try_acquire_recursive(NAME) __libc_lock_try_acquire_recursive(&(NAME))
#define __lock_release(NAME) __libc_lock_release(&(NAME))
#define __lock_release_recursive(NAME) __libc_lock_release_recursive(&(NAME))

#endif /* __SYS_LOCK_H__ */
