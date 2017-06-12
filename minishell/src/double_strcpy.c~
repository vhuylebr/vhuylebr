/*
** double_strcpy.c for dblcpy in /home/vhuylebr/Desktop/PSU_2016_minishell1
**
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
**
** Started on  Mon Jan 16 16:22:52 2017 valerian huylebroeck
** Last update Thu May 18 09:57:10 2017 valerian huylebroeck
*/

#include <stdlib.h>
#include "minishell.h"

char	**free_tab(char **to_free, char **envcpy)
{
  int	i;

  i = 0;
  while (to_free[i])
    {
      free(to_free[i]);
      i++;
    }
  free(to_free);
  return (envcpy);
}

char	**tab_cpy(char **tab)
{
  int	i;
  char	**cpy;

  i = 0;
  while (tab[i])
    ++i;
  cpy = malloc(sizeof(char*) * (i + 3));
  i = 0;
  while (tab[i])
    {
      cpy[i] = strdup(tab[i]);
      ++i;
    }
  cpy[i] = NULL;
  cpy[i + 1] = NULL;
  return (cpy);
}

int	find(char **envcpy, char *str)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (envcpy[y])
    {
      if (my_strncmp(envcpy[y], str, len(str)) == 0)
	return (y);
      ++y;
    }
  return (-1);
}
