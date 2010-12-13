/* <dir.h>

 provides prototypes for custom directory functions in libsysbase

*/
#ifndef __DIR_H__
#define __DIR_H__

#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Directory iterator for mantaining state between dir* calls */
typedef struct {
	int device;
	void *dirStruct;
} DIR_ITER;

DIR_ITER* diropen (const char *path);
int dirreset (DIR_ITER *dirState);
int dirnext (DIR_ITER *dirState, char *filename, struct stat *filestat);
int dirclose (DIR_ITER *dirState);


#ifdef __cplusplus
}
#endif

#endif // __DIR_H__ 