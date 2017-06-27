/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_del_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:22:39 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 13:01:09 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_refresh(t_window *size, t_clist **list, struct termios *term)
{
	ft_unset_term(term);
	ft_set_term(term);
	ft_get_size(size);
	ft_print_all(size, list);
}

t_clist		*what_arrow(int drctn, t_window *size,
		t_clist **list, t_clist *cursor)
{
	if (drctn == 1)
		cursor = ft_move_up(size, list, cursor);
	if (drctn == 2)
		cursor = ft_move_down(size, list, cursor);
	if (drctn == 3)
		cursor = ft_move_right(size, list, cursor);
	if (drctn == 4)
		cursor = ft_move_left(size, list, cursor);
	return (cursor);
}

t_clist		*ft_select(t_window *size, t_clist **list, t_clist *cursor)
{
	if (cursor->is_selected)
		cursor->is_selected = 0;
	else
	{
		cursor->is_selected = 1;
		cursor->is_cursor = 0;
		if (cursor->next)
			cursor = cursor->next;
		else
			cursor = list_start(cursor);
		cursor->is_cursor = 1;
	}
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}

t_clist		*ft_del_cursor(t_window *size, t_clist **list, t_clist *cursor)
{
	cursor = ft_del_lst_cursor(list, cursor);
	if (cursor == NULL)
		return (NULL);
	cursor->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (cursor);
}
