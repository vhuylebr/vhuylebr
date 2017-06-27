/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:22:12 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 12:45:14 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist	*ft_move_up(t_window *size, t_clist **list, t_clist *cursor)
{
	cursor->is_cursor = 0;
	if (cursor->prev)
		cursor = cursor->prev;
	else
	{
		while (cursor->next)
			cursor = cursor->next;
	}
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}

t_clist	*ft_move_down(t_window *size, t_clist **list, t_clist *cursor)
{
	cursor->is_cursor = 0;
	if (cursor->next)
		cursor = cursor->next;
	else
	{
		while (cursor->prev)
			cursor = cursor->prev;
	}
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}

t_clist	*ft_move_left(t_window *size, t_clist **list, t_clist *cursor)
{
	int	i;

	i = 0;
	cursor->is_cursor = 0;
	while (i < size->li)
	{
		if (cursor->prev)
			cursor = cursor->prev;
		else
		{
			while (cursor->next)
				cursor = cursor->next;
		}
		i++;
	}
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}

t_clist	*ft_move_right(t_window *size, t_clist **list, t_clist *cursor)
{
	int	i;

	i = 0;
	cursor->is_cursor = 0;
	while (i < size->li)
	{
		if (cursor->next)
			cursor = cursor->next;
		else
		{
			while (cursor->prev)
				cursor = cursor->prev;
		}
		i++;
	}
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}
