/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:18:51 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 22:00:17 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE	1

struct		s_gnl
{
	char	*st_str;
	int		size;
	int		fd;
	char	*str;
};

/*
**	get_next_line.c
*/

int			get_next_line(const int fd, char **line);

#endif
