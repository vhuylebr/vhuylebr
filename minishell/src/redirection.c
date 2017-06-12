/*
** redirection.c for redir in /home/vhuylebr/Desktop/PSU_2016_minishell2/src
**
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
**
** Started on  Wed Apr  5 14:39:05 2017 valerian huylebroeck
** Last update Sun May 21 20:09:40 2017 valerian huylebroeck
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell.h"

int	search_double_redir(char **s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (s[y])
    {
      while (s[y][x])
	{
	  if (s[y][x] == '"')
	    while (s[y][x + 1] != '"' && s[y][x + 1])
	      ++x;
	  if (s[y][x] == '>' && s[y][x + 1] == '>' && x == 0 &&
	      s[y][2] == '\0' && s[y + 1] && y != 0)
	    return (y);
	  ++x;
	}
      ++y;
      x = 0;
    }
  return (-1);
}

void	double_redirection(char **s, char **envcpy, char **PATH, int y)
{
  int	fd;
  int	x;
  char	*tmp;

  x = 0;
  fd = -1;
  while (s[y][x] != '>')
    ++x;
  if (x == 0 && s[y + 1] && s[y][x + 2] == '\0')
    fd = open(s[y + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
  else
    {
      tmp = s[y] + x + 2;
      if (tmp[0] != '\0')
	fd = open(s[y] + x + 2, O_RDWR | O_CREAT | O_APPEND, 0644);
      else if (s[y + 1])
	fd = open(s[y + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
    }
  change(s, x, y);
  redirection_exe(PATH, s, envcpy, fd);
}

int	redirection(char **s, char **envcpy, char **PATH, int y)
{
  int	fd;
  int	x;
  char	*tmp;

  x = 0;
  fd = -1;
  while (s[y][x] != '>')
    ++x;
  if (x == 0 && s[y + 1] && s[y][x + 1] == '\0')
    fd = open(s[y + 1], O_RDWR | O_CREAT, 0644);
  else
    {
      tmp = s[y] + x + 1;
      if (tmp[0] != '\0')
	fd = open(s[y] + x + 1, O_RDWR | O_CREAT, 0644);
      else if (s[y + 1])
	fd = open(s[y + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
    }
  change2(s, x, y);
  if (redirection_exe(PATH, s, envcpy, fd) == -1)
    return (-1);
  return (0);
}

int	search_simple_redirection(char **s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (s[y])
    {
      while (s[y][x])
	{
	  if (s[y][x] == '"')
	    while (s[y][x + 1] != '"' && s[y][x + 1])
	      ++x;
	  if (s[y][x] == '>' && x == 0 && s[y][1] == '\0' &&
	      s[y + 1] && y != 0)
	    return (y);
	  ++x;
	}
      ++y;
      x = 0;
    }
  return (-1);
}

int	  redirection_exe(char **PATH, char **s, char **envcpy, int fd)
{
  int	i;
  pid_t	pid;

  i = 0;
  while (PATH[i])
    {
      PATH[i] = strcat(PATH[i], "/");
      if (access(strcat(PATH[i], s[0]), F_OK | X_OK) != -1) // fair si cest l'exe dun fichier
	     {
	        if ((pid = fork()) == 0)
	         {
	          dup2(fd, 1);
	          dup2(fd, 2);
	          close(fd);
	          if ((s[0]) && execve(PATH[i], s, envcpy) == -1)
		           return (-1);
	          }
	         wait(&pid);
	         return (0);
        }
      ++i;
    }
  return (-1);
}
