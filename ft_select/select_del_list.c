
#include "ft_select.h"

void	ft_refresh(t_window *size, t_clist **list, struct termios *term)
{
	ft_unset_stage(term);
	ft_set_stage(term);
	ft_get_size(size);
	ft_print(size, list);
}

t_clist	*what_arrow(int drctn, t_window *size, t_clist **list, t_clist *item)
{
	if (drctn == 1)
		item = ft_move_up(size, list, item);
	if (drctn == 2)
		item = ft_move_down(size, list, item);
	if (drctn == 3)
		item = ft_move_right(size, list, item);
	if (drctn == 4)
		item = ft_move_left(size, list, item);
	return (item);
}


t_clist	*ft_select(t_window *size, t_clist **list, t_clist *item)
{
	if (item->is_selected)
		item->is_selected = 0;
	else
	{
		item->is_selected = 1;
		item->is_cursor = 0;
		if (item->next)
				item = item->next;
		else
			item = list_start(item);
		item->is_cursor = 1;
	}
	ft_get_size(size);
	ft_print(size, list);
	return (item);
}

t_clist	*ft_del_item(t_window *size, t_clist **list, t_clist *item)
{
	item = ft_del_lst_item(list, item);
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print(size, list);
	return (item);
}
