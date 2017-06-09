/*
** get_next_line.h for gnl in /home/vhuylebr/Desktop/CPE_2016_matchstick/include
**
** Made by valerian huylebroeck
** Login   <vhuylebr@epitech.net>
**
** Started on  Sun Feb 26 13:07:53 2017 valerian huylebroeck
** Last update Wed May 17 14:27:04 2017 Leandro Braga
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE	100

struct	s_gnl
{
  char	*st_str;
  int	size;
  int	fd;
  char	*str;
};

/* get_next_line.c */
int	get_next_line(const int fd, char **line);

#endif /* !GET_NEXT_LINE_H_ */
