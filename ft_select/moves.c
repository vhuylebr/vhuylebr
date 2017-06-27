/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:22:12 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:22:29 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist *go_to_letter(char c, t_window *size, t_clist **list, t_clist *item)
{
  if(item->str[0] != c)
    item = *list;
  else
    item->is_cursor = 0;
  while (item->next)
    {
      item = item->next;
      if (item->str[0] == c)
	{
	  item->is_cursor = 1;
	  ft_get_size(size);
	  ft_print_all(size, list);
	  return (item);
	}
    }
  return (item);
}

t_clist	*ft_move_up(t_window *size, t_clist **list, t_clist *item)
{
	item->is_cursor = 0;
	if (item->prev)
		item = item->prev;
	else
	{
		while (item->next)
			item = item->next;
	}
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (item);
}

t_clist	*ft_move_down(t_window *size, t_clist **list, t_clist *item)
{
	item->is_cursor = 0;
	if (item->next)
		item = item->next;
	else
	{
		while (item->prev)
			item = item->prev;
	}
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (item);
}

t_clist	*ft_move_left(t_window *size, t_clist **list, t_clist *item)
{
	int	i;

	i = 0;
	item->is_cursor = 0;
	while (i < size->items_per_tab)
	{
		if (item->prev)
			item = item->prev;
		else
		{
			while (item->next)
				item = item->next;
		}
		i++;
	}
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (item);
}

t_clist	*ft_move_right(t_window *size, t_clist **list, t_clist *item)
{
	int	i;

	i = 0;
	item->is_cursor = 0;
	while (i < size->items_per_tab)
	{
		if (item->next)
			item = item->next;
		else
		{
			while (item->prev)
				item = item->prev;
		}
		i++;
	}
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print_all(size, list);
	return (item);
}
