/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:28:07 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 22:47:14 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minishell.h"

int		exe_file(char **s, char **envcpy)
{
	pid_t	pid;
	DIR		*dir;

	if ((dir = opendir(s[0])))
		ft_printf(1, "IS_DIR\n", 0);
	else if (access(s[0], F_OK | X_OK) != -1)
	{
		if ((pid = fork()) == 0)
		{
			if (execve(s[0], s, envcpy) == -1)
				ft_printf(2, "error\n", 0);
		}
		else
			wait(&pid);
		if (WTERMSIG(pid) == 11)
			return (ft_printf(2, "%s\n", 11, SEGF_DUMP));
	}
	else if (access(s[0], F_OK) == -1)
		return (ft_printf(2, "%s: %s: %s\n", -1, PROMPT, s[0], NOT_FOUND));
	else if (access(s[0], X_OK) == -1)
		return (ft_printf(2, "%s: %s: %s\n", -1, PROMPT, s[0], NO_PERMISSION));
	return (0);
}

int		verif_pipe(char **s)
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
			if (s[y][x] == '|')
				return (y);
			++x;
		}
		++y;
		x = 0;
	}
	return (-1);
}

char	**env_exe(char **path, char **s, char **envcpy, int i)
{
	pid_t	pid;
	DIR		*dir;

	pid = 0;
	if (s[0][0] == '\0')
		return (NULL);
	if ((dir = opendir(s[0])))
		return (bonus_cd(dir, s[0], envcpy));
	while (path[i])
	{
		path[i] = strcat(path[i], "/");
		if (access(strcat(path[i], s[0]), F_OK | X_OK) != -1)
		{
			if ((pid = fork()) == 0)
			{
				if ((s[0]) && execve(path[i], s, envcpy) == -1)
					return (envcpy);
			}
			wait(&pid);
			return (envcpy);
		}
		++i;
	}
	return (NULL);
}

int		return_n_free(char **tab, char **s, int y)
{
	if (tab != NULL)
		free_tab(tab, NULL);
	if (s != NULL)
		free_tab(s, NULL);
	if (y >= 1)
		return (1);
	return (0);
}

int		exe(char **s, char ***env, int y, int path_y)
{
	char	**path;
	char	**envcpy;

	envcpy = *env;
	if (s == NULL)
		return (0);
	if (path_y == -1)
	{
		y = next_check(s, &envcpy, 0);
		*env = envcpy;
		return (return_n_free(NULL, s, y));
	}
	path = my_strsplit2(envcpy[path_y], ':', ft_n(envcpy[path_y],
				':', 0, 0), 0);
	if ((y = search_double_redir(s)) != -1 && verif_pipe(s) == -1)
		double_redirection(s, envcpy, path, y);
	else if ((y = search_simple_redirection(s)) != -1 &&
			verif_pipe(s) == -1)
		y = redirection(s, envcpy, path, y);
	else if (strcmp("cd", s[0]) != 0 && env_exe(path, s, envcpy, 0) != NULL)
		;
	else
		y = next_check(s, &envcpy, 0);
	*env = envcpy;
	return (return_n_free(path, s, y));
}
