#include <sys/syscalls.h>

struct __syscalls_t __syscalls = {
	NULL,			//	sbrk_r
	NULL,			//	close_r
	NULL,			//	open_r
	NULL,			//	read_r
	NULL,			//	write_r
	NULL,			//	lseek_r
	NULL,			//	fstat_r
	NULL,			//	ftruncate_r
	NULL,			//	fsync_r
	NULL,			//	unlink_r
	NULL,			//	chmod_r
	NULL,			//	execve_r
	NULL,			//	gettod_r
	NULL,			//  sys_lwmutex_create_r
	NULL,			//	sys_lwmutex_destroy_r
	NULL,			//	sys_lwmutex_lock_r
	NULL,			//	sys_lwmutex_trylock_r
	NULL,			//	sys_lwmutex_unlock_r
	NULL			//	exit
};
