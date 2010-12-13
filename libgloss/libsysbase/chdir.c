#include <unistd.h>
#include <reent.h>
#include <string.h>
#include <errno.h>

#define DIRECTORY_SEPERATOR_CHAR	'/'

const char DIRECTORY_SEPERATOR[] = "/";
const char DIRECTORY_THIS[] = ".";
const char DIRECTORY_PARENT[] = "..";

static char _current_working_directory[MAXPATHLEN] = "/";

int _concatenate_path(struct _reent *r,char *path,const char *extra,int maxLength)
{
	return -1;
}

int chdir(const char *path)
{
	const char *pathPosition;
	struct _reent *r = _REENT;
	char temp_cwd[MAXPATHLEN];

	if(strnlen(path,MAXPATHLEN + 1)>=MAXPATHLEN) {
		r->_errno = ENAMETOOLONG;
		return -1;
	}

	strncpy(temp_cwd,_current_working_directory,MAXPATHLEN);

	return -1;
}

char* getcwd(char *buf,size_t size)
{
	struct _reent *r = _REENT;

	if(size==0) {
		r->_errno = EINVAL;
		return NULL;
	}

	if(size<(strnlen(_current_working_directory,MAXPATHLEN) + 1)) {
		r->_errno = ERANGE;
		return NULL;
	}

	strncpy(buf,_current_working_directory,size);
	return buf;
}
