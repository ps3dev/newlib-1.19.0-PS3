#include <reent.h>

static __thread struct _reent t_reent;
static __thread struct _reent *t_reentp = 0;

struct _reent* __getreent(void)
{
  struct _reent *r = t_reentp;

	if(!r) {
    t_reentp = r = &t_reent;
    _REENT_INIT_PTR(r);
  }
  return r;
}
