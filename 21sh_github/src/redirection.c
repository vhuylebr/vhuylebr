/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:42:38 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 18:39:40 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_double_redir(char **s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (s == NULL)
		return (-1);
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

void	double_redirection(char **s, char **envcpy, char **path, int y)
{
	int		fd;
	int		x;
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
	redirection_exe(path, s, envcpy, fd);
}

int		redirection(char **s, char **envcpy, char **path, int y)
{
	int		fd;
	int		x;
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
	if (redirection_exe(path, s, envcpy, fd) == -1)
		return (-1);
	return (0);
}

int		search_simple_redirection(char **s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (s == NULL)
		return (-1);
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

int		redirection_exe(char **path, char **s, char **envcpy, int fd)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (path[i])
	{
		path[i] = strcat(path[i], "/");
		if (access(strcat(path[i], s[0]), F_OK | X_OK) != -1)
		{
			if ((pid = fork()) == 0)
			{
				dup2(fd, 1);
				dup2(fd, 2);
				close(fd);
				if ((s[0]) && execve(path[i], s, envcpy) == -1)
					return (-1);
			}
			wait(&pid);
			return (0);
		}
		++i;
	}
	return (-1);
}
