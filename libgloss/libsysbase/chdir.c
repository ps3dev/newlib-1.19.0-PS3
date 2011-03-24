#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>
#include <sys/syscalls.h>

int _concatenate_path(struct _reent *r,char *path,const char *extra,int maxLength)
{
	return -1;
}

int chdir(const char *path)
{
	struct _reent *r = _REENT;
	
	if(__syscalls.chdir_r)
		return __syscalls.chdir_r(r,path);

	r->_errno = ENOSYS;
	return -1;
}

char* getcwd(char *buf,size_t size)
{
	struct _reent *r = _REENT;

	if(__syscalls.getcwd_r)
		return __syscalls.getcwd_r(r,buf,size);

	r->_errno = ENOSYS;
	return NULL;
}
