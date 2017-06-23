

#include "ft_select.h"

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
	ft_print(size, list);
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
	ft_print(size, list);
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
	ft_print(size, list);
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
	ft_print(size, list);
	return (item);
}
