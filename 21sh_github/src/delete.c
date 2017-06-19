/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:27:28 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/19 17:31:09 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char *g_left;
extern char *g_right;

int		ft_delete(char **s, int i)
{
	char	*tmp;
	char	*str;
	int		k;

	k = 0;
	str = *s;
	if (str[0] == '\0')
		return (i);
	tmp = strdup(str + i);
	str[i - 1] = 0;
	*s = strjoin(str, tmp);
	--i;
	ft_printf(1, g_left, 0);
	ft_printf(1, tmp, 0);
	ft_putchar_fd(' ', 1);
	k = strlen(tmp) + 1;
	while (k--)
		ft_printf(1, g_left, 0);
	free(tmp);
	free(str);
	return (i);
}

int		add_char_to_str(char **s, int k, char c)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	str = *s;
	tmp = malloc(strlen(str) + 2);
	while (str[i])
	{
		tmp[i] = str[i];
		++i;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	*s = tmp;
	ft_putchar_fd(c, 1);
	return (k + 1);
}
