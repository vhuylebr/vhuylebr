/*
** utils.c for 42sh in /home/vhuylebr/rendu/CPool_Day07
**
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
**
** Started on  Tue Oct 11 08:16:49 2016 valerian huylebroeck
** Last update Wed May 17 14:28:32 2017 Leandro Braga
*/

#include <stdlib.h>
#include "minishell.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]) && (i < (n - 1)))
    ++i;
  return (s1[i] - s2[i]);
}

char	*strnew(size_t size)
{
  char	*str;

  if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
    return (0);
  str[size] = '\0';
  while (size > 0)
    str[size-- - 1] = '\0';
  return (str);
}

char	*strjoin(char const *s1, char const *s2)
{
  int	x;
  int	len_s1;
  int	len_s2;
  char	*str;

  x = 0;
  if (s1 && s2)
    {
      len_s1 = strlen(s1);
      len_s2 = strlen(s2);
      if (!(str = (char *)malloc(sizeof(char*) * (len_s1 + len_s2 + 1))))
	return (0);
      while (x < len_s1)
	str[x++] = *s1++;
      while (x < len_s1 + len_s2)
	str[x++] = *s2++;
      str[x] = '\0';
      return (str);
    }
  return (NULL);
}
