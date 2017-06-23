

#include "ft_select.h"

char	*ft_strnew(size_t size)
{
  char	*str;

  if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
    return (0);
  str[size] = '\0';
  while (size > 0)
    str[size-- - 1] = '\0';
  return (str);
}
