/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:15:20 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 16:49:11 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		num_tab_needed(t_window *size, t_clist **list)
{
	int	i;

	size->listcount = ft_clistcount(list);
	i = 1;
	while (size->li <= size->listcount / i)
		++i;
	return (i);
}

static void	ft_fill_struct_window(t_window *size, t_clist **list)
{
	ft_get_size(size);
	size->tab_counter = 1;
	size->arg_printed = 0;
	size->num_tab = num_tab_needed(size, list); /*nb ligne < ac*/
	size->max_len = ft_maxlen(list); /* size de argv le plus grand*/
	//size->items_per_tab = size->co / size->max_len;
	size->items_per_tab = size->listcount / size->num_tab + 1;
	while (size->co <= (size->max_len + 2) * size->num_tab)
	{
		ft_putstr_fd(tgetstr("cl", NULL), 1);
		ft_get_size(size);
		size->num_tab = num_tab_needed(size, list);
	}
}

void	ft_print_item(t_clist *item)
{
	if (item->is_cursor)
	  tputs(tgetstr("us", NULL), TPUTS_END); /* us = surligne*/
	if (item->is_selected)
	  tputs(tgetstr("mr", NULL), TPUTS_END); /* mr = reverse-video mode */
		ici pour les couleurs
	ft_putstr_fd(item->str, FD);
	tputs(tgetstr("me", NULL), TPUTS_END); /* me = to turn off all appearance modes*/
}

void	ft_print(t_window *size, t_clist **list)
{
	t_clist	*lst;
	int		tabs;

	tputs(tgetstr("cl", NULL), TPUTS_END);
	ft_fill_struct_window(size, list);
	lst = *list;
	tabs = size->arg_printed;
	if (tabs < size->max_len && size->num_tab + 2 * size->max_len < size->co)
	{
		tabs = size->max_len + 2;
		size->tab_counter = 0;
	}
	while (lst->next != NULL)
	{
		ft_print_item(lst);
		size->arg_printed++;//= size->max_len + 1; /* X */
		if (size->arg_printed >= size->items_per_tab)// * size->max_len)
		{
		  size->tab_counter += size->max_len + 2; /* Y */
		  size->arg_printed = 0;
		}
		tputs(tgoto(GET_CM, size->tab_counter, size->arg_printed), TPUTS_END); /* curseur */
		lst = lst->next;
	}
	ft_print_item(lst);
}
