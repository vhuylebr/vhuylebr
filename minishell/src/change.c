/*
** change.c for change in /home/vhuylebr/Desktop/PSU_2016_minishell2/src
** 
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
** 
** Started on  Sun Apr  9 17:48:04 2017 valerian huylebroeck
** Last update Sun Apr  9 17:56:56 2017 valerian huylebroeck
*/

#include <stdlib.h>

void	change(char **s, int x, int y)
{
  if (y == 0 && s[y + 1] == NULL)
    s[y][x] = '\0';
  else if (s[y][0] == '>' && s[y][2] == '\0')
    s[y] = NULL;
  else if (s[y][x + 2] == '\0' && s[y + 1])
    {
      s[y][x] = '\0';
      s[y + 1] = NULL;
    }
  else if (s[y][0] == '>' && s[y][1] != '\0')
    s[y] = NULL;
}

void	change2(char **s, int x, int y)
{
  if (y == 0 && s[y + 1] == NULL)
    {
      s[y][x] = '\0';
      s[y + 1] = NULL;
    }
  else if (s[y][0] == '>' && s[y][1] == '\0')
    s[y] = NULL;
  else if (s[y][x + 1] == '\0' && s[y + 1])
    {
      s[y][x] = '\0';
      s[y + 1] = NULL;
    }
  else if (s[y][0] == '>' && s[y][2] != '\0')
    s[y] = NULL;
}
