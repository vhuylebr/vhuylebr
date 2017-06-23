

#include "ft_select.h"

t_clist	*ft_del_lst_item(t_clist **old, t_clist *item)
{
	t_clist	*tmpprev;
	t_clist	*tmpnext;

	if ((!(item->next)||!(item->prev)))
	{
		tmpnext = ft_del_start_end(old, item);
		return (tmpnext);
	}
	tmpnext = item->next;
	tmpprev = item->prev;
	tmpprev->next = tmpnext;
	tmpnext->prev = tmpprev;
	free(item->str);
	free(item);
	item = NULL;
	return (tmpnext);
}

t_clist	*ft_del_start_end(t_clist **old, t_clist *item)
{
	t_clist	*tmp;

	if (item->next == NULL && item->prev == NULL)
	{
		tmp = ft_clstnew("");
		ft_list_del(old);
		*old = tmp;
	}
	else if (item->next)
	{
		tmp = item->next;
		tmp->prev = NULL;
		free(item->str);
		free(item);
		*old = tmp;
	}
	else
	{
		tmp = item->prev;
		tmp->next = NULL;
		free(item->str);
		free(item);
		return (list_start(tmp));
	}
	return (tmp);
}

t_clist	*list_end(t_clist *item)
{
	while (item->next)
		item = item->next;
	return (item);
}

t_clist	*list_start(t_clist *item)
{
	while (item->prev)
		item = item->prev;
	return (item);
}
