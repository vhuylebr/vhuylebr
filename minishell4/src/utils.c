/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:39:45 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 17:16:09 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		aff_tab(char **str, int opt)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putstr(str[i]);
			if (opt == 2)
				ft_putstr(" ");
			if (opt == 1)
				ft_putstr("\n");
			++i;
		}
		return (0);
	}
	return (-1);
}

int		my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		my_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]) && (i < (n - 1)))
		++i;
	return (s1[i] - s2[i]);
}

char	*strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (0);
	str[size] = '\0';
	while (size > 0)
		str[size-- - 1] = '\0';
	return (str);
}

char	*strjoin(char const *s1, char const *s2)
{
	int		x;
	int		len_s1;
	int		len_s2;
	char	*str;

	x = 0;
	if (s1 && s2)
	{
		len_s1 = strlen(s1);
		len_s2 = strlen(s2);
		if (!(str = (char *)malloc(sizeof(char*) * (len_s1 + len_s2 + 1))))
			return (0);
		while (x < len_s1)
			str[x++] = *s1++;
		while (x < len_s1 + len_s2)
			str[x++] = *s2++;
		str[x] = '\0';
		return (str);
	}
	return (NULL);
}
