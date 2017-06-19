/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:42:06 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 20:34:47 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

int		verif_setenv(char **s)
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while ((s[i][k] >= '0' && s[i][k] <= '9') ||
			(s[i][k] >= 'a' && s[i][k] <= 'z') ||
			(s[i][k] >= 'A' && s[i][k] <= 'Z'))
		++k;
	if (s[i][k])
		return (ft_printf(2, "%s caracters.\n", -1, ALPHANUM_SETENV));
	return (0);
}

void	no_leaks(char **tmp, char *s1, char *s2)
{
	char *leak;

	leak = strjoin(tmp[find(tmp, s1)], s2);
	free(tmp[find(tmp, s1)]);
	tmp[find(tmp, s1)] = leak;
}

void	no_leaks_2(char **tmp, int i, char *s1)
{
	char	*leak;

	leak = strjoin(tmp[i], s1);
	free(tmp[i]);
	tmp[i] = leak;
}

int		add_env(char **tmp, char **s)
{
	int	i;

	i = 0;
	if (s[1] == NULL)
		return (aff_tab(tmp, 1));
	if (verif_setenv(s) == -1)
		return (1);
	if (find(tmp, s[1]) != -1 && tmp[find(tmp, s[1])][len(s[1])] == '=')
	{
		tmp[find(tmp, s[1])][len(s[1]) + 1] = '\0';
		if (s[2])
			no_leaks(tmp, s[1], s[2]);
		return (0);
	}
	while (tmp[i])
		i++;
	tmp[i] = strdup(s[1]);
	no_leaks_2(tmp, i, "=");
	if (s[2] == NULL)
		no_leaks_2(tmp, i, "");
	else if (s[3] != NULL)
		return (ft_printf(2, "%s\n", -1, SETENV_ERR));
	else
		no_leaks_2(tmp, i, s[2]);
	return (0);
}

int		remove_env(char **envcpy, char **s)
{
	int	i;

	i = 0;
	if (s[1] == NULL)
		return (ft_printf(2, "%s\n", 2, UNSETENV_ERR));
	while (envcpy[i] && my_strncmp(envcpy[i], s[1], len(s[1])) != 0)
	{
		if (my_strncmp(envcpy[i], s[1], len(s[1])) == 0 &&
				envcpy[i][len(s[1])] != '=')
			++i;
		++i;
	}
	if (envcpy[i] == NULL)
		return (0);
	free(envcpy[i]);
	while (envcpy[i + 1])
	{
		envcpy[i] = envcpy[i + 1];
		++i;
	}
	envcpy[i] = NULL;
	return (0);
}
