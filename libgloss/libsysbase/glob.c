#include <glob.h>
#include <errno.h>

int glob(const char *pattern,int flags,int (*errfunc)(const char *epath,int eerrno),glob_t *pglob)
{
	if(errfunc)
		errfunc((void*)0,ENOSYS);
  return 0;
}
