/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:24:41 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:25:20 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_maxlen(t_clist **list)
{
	int		i;
	int		len;
	t_clist	*ls;

	len = 0;
	i = 0;
	ls = *list;
	while (ls->next != NULL)
	{
		while (ls->str[i] != '\0')
		{
			if (i > len)
				len = i;
			i++;
		}
		ls = ls->next;
		i = 0;
	}
	return (len + 1);
}
