/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:00:15 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 13:00:56 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist	*ft_del_lst_cursor(t_clist **old, t_clist *cursor)
{
	t_clist	*tmpprev;
	t_clist	*tmpnext;

	if ((!(cursor->next) || !(cursor->prev)))
	{
		tmpnext = ft_del_start_end(old, cursor);
		return (tmpnext);
	}
	tmpnext = cursor->next;
	tmpprev = cursor->prev;
	tmpprev->next = tmpnext;
	tmpnext->prev = tmpprev;
	free(cursor->str);
	free(cursor);
	cursor = NULL;
	return (tmpnext);
}

t_clist	*ft_del_start_end(t_clist **old, t_clist *cursor)
{
	t_clist	*tmp;

	if (cursor->next == NULL && cursor->prev == NULL)
	{
		tmp = NULL;
		ft_list_del(old);
		*old = tmp;
	}
	else if (cursor->next)
	{
		tmp = cursor->next;
		tmp->prev = NULL;
		free(cursor->str);
		free(cursor);
		*old = tmp;
	}
	else
	{
		tmp = cursor->prev;
		tmp->next = NULL;
		free(cursor->str);
		free(cursor);
		return (list_start(tmp));
	}
	return (tmp);
}

t_clist	*list_end(t_clist *cursor)
{
	while (cursor->next)
		cursor = cursor->next;
	return (cursor);
}

t_clist	*list_start(t_clist *cursor)
{
	while (cursor->prev)
		cursor = cursor->prev;
	return (cursor);
}
