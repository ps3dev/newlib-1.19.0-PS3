#ifndef _SYS_DIRENT_H
# define _SYS_DIRENT_H

#include <stdint.h>
#include <unistd.h>

typedef struct __dirdesc {
	int32_t	dd_fd;
	char	dd_buf[];
} DIR;

# define __dirfd(dp)	((dp)->dd_fd)

struct dirent {
	uint8_t		d_type;
	uint8_t		d_namlen;
	char		d_name[MAXPATHLEN + 1];
};

DIR *opendir (const char *);
struct dirent *readdir (DIR *);
int closedir (DIR *);

#endif
