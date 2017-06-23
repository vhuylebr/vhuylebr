#include "ft_select.h"

int             is_rtn(char *buf)
{
  return (buf[0] == 10);
}

int             is_esc(char *buf)
{
  return (buf[0] == 27 && buf[1] == 10);
}

int             is_cntrl_z(char *buf)
{
  return (buf[0] == 26);
}

int             is_cntrl_c(char *buf)
{
  return (buf[0] == 3);
}

int             is_alt_r(char *buf)
{
  return (buf[0] == -62);
}
