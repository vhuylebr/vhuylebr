/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:40:15 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/17 17:46:29 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	change(char **s, int x, int y)
{
	if (y == 0 && s[y + 1] == NULL)
		s[y][x] = '\0';
	else if (s[y][0] == '>' && s[y][2] == '\0')
	{
		free(s[y]);
		s[y] = NULL;
		while (s[y + 1])
			free(s[y++ + 1]);
	}
	else if (s[y][x + 2] == '\0' && s[y + 1])
	{
		s[y][x] = '\0';
		free(s[y + 1]);
		s[y + 1] = NULL;
	}
	else if (s[y][0] == '>' && s[y][1] != '\0')
	{
		free(s[y]);
		s[y] = NULL;
	}
}

void	change2(char **s, int x, int y)
{
	if (y == 0 && s[y + 1] == NULL)
	{
		s[y][x] = '\0';
		s[y + 1] = NULL;
	}
	else if (s[y][0] == '>' && s[y][1] == '\0')
	{
		free(s[y]);
		s[y] = NULL;
		if (s[y + 1])
			while (s[y + 1])
				free(s[y++ + 1]);
	}
	else if (s[y][x + 1] == '\0' && s[y + 1])
	{
		s[y][x] = '\0';
		s[y + 1] = NULL;
	}
	else if (s[y][0] == '>' && s[y][2] != '\0')
	{
		if (s[y])
			free(s[y]);
		s[y] = NULL;
	}
}
