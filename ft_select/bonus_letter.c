/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:49:49 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 13:01:21 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist		*ocur(t_window *size, t_clist **list, t_clist *cursor)
{
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}

t_clist		*go_to_letter(char c, t_window *size, t_clist **list,
	t_clist *cursor)
{
	t_clist	*tmp;

	tmp = cursor;
	cursor->is_cursor = 0;
	while (cursor->next)
	{
		cursor = cursor->next;
		if (cursor->str[0] == c)
			return (ocur(size, list, cursor));
	}
	cursor = *list;
	while (cursor->next)
	{
		cursor = cursor->next;
		if (cursor->str[0] == c)
			return (ocur(size, list, cursor));
	}
	tmp->is_cursor = 1;
	return (tmp);
}
