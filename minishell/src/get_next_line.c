/*
** get_next_line.c for gnl in /home/vhuylebr/Desktop/GNL_final
**
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
**
** Started on  Mon Feb 13 21:29:07 2017 valerian huylebroeck
** Last update Wed May 17 14:23:32 2017 Leandro Braga
*/

#include "minishell.h"
#include "get_next_line.h"

int	vrf(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      ++i;
    }
  return (-1);
}

int	s(char *st_str, int ret, char *str, char **line)
{
  int	i;
  char	*tmp;

  i = 0;
  ++ret;
  tmp = strjoin(str, st_str);
  tmp[vrf(tmp)] = '\0';
  while (st_str[ret] != '\0')
    st_str[i++] = st_str[ret++];
  st_str[i] = '\0';
  if ((*line = strdup(tmp)) == NULL)
    return (-1);
  free(str);
  free(tmp);
  return (1);
}

char	*erase_leaks(char *str, char *st_str)
{
  char	*tmp;

  tmp = strjoin(str, st_str);
  free(str);
  str = strdup(tmp);
  free(tmp);
  tmp = NULL;
  return (str);
}

int			get_next_line(const int fd, char **line)
{
  static struct s_gnl	gnl[1095];

  if (BUFF_SIZE < 1 || !line || fd < 0)
    return (-1);
  if (gnl[fd].st_str == NULL)
    gnl[fd].st_str = strnew(BUFF_SIZE);
  gnl[fd].str = strdup(gnl[fd].st_str);
  if (vrf(gnl[fd].str) != -1)
    return (s(gnl[fd].st_str, vrf(gnl[fd].st_str), gnl[fd].str, line));
  while ((gnl[fd].size = read(fd, gnl[fd].st_str, BUFF_SIZE)) > 0)
    {
      gnl[fd].st_str[gnl[fd].size] = '\0';
      if (vrf(gnl[fd].st_str) != -1)
	return (s(gnl[fd].st_str, vrf(gnl[fd].st_str), gnl[fd].str, line));
      gnl[fd].str = erase_leaks(gnl[fd].str, gnl[fd].st_str);
    }
  if (gnl[fd].size == -1)
    return (-1);
  if (gnl[fd].size == 0 && (strlen(gnl[fd].st_str) == 0))
    return (0);
  gnl[fd].st_str = strnew(1);
  if (!(*line = strdup(gnl[fd].str)))
    return (-1);
  return (1);
}
