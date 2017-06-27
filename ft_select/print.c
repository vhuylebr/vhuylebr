/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:18:06 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:26:03 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>

int				num_col_needed(t_window *size, t_clist **list)
{
	int	i;

	size->listcount = ft_clistcount(list);
	i = 1;
	while (size->li <= size->listcount / i)
		++i;
	return (i);
}

static int		ft_fill_struct_window(t_window *size, t_clist **list)
{
  t_clist *tmp;
  int	i;

  i = 1;
	ft_get_size(size);
	size->tab_counter = 1;
	size->arg_printed = 0;
	size->num_tab = num_col_needed(size, list);
	size->max_len = ft_maxlen(list);
	size->items_per_tab = size->listcount / size->num_tab + 1;
	if (size->co <= (size->max_len + 2) * size->num_tab)
	  {
	    tmp = *list;
	    while (tmp->is_cursor == 0)
	      {
		++i;
		tmp = tmp->next;
	      }
	    return (i / size->li * size->li);
	    /*		ft_putstr_fd(tgetstr("cl", NULL), 1);*/
		ft_get_size(size);
		/*size->num_tab = num_col_needed(size, list);*/
	}
	return (0);
	
}

void			ft_print_item(t_clist *item)
{
	struct stat	filestat;

	if (item->is_cursor)
		ft_putstr_fd(tgetstr("us", NULL), 1);
	if (item->is_selected)
		ft_putstr_fd(tgetstr("mr", NULL), 1);
	if (lstat(item->str, &filestat) >= 0)
	{
		ft_putstr_fd(C_BOLD, 1);
		S_ISBLK(filestat.st_mode) ? ft_putstr_fd(C_RED, 1) : NULL;
		S_ISCHR(filestat.st_mode) ? ft_putstr_fd(C_BLUE, 1) : NULL;
		S_ISDIR(filestat.st_mode) ? ft_putstr_fd(C_CYAN, 1) : NULL;
		S_ISFIFO(filestat.st_mode) ? ft_putstr_fd(C_BROWN, 1) : NULL;
		S_ISLNK(filestat.st_mode) ? ft_putstr_fd(C_GREEN, 1) : NULL;
		S_ISSOCK(filestat.st_mode) ? ft_putstr_fd(C_MAGENTA, 1) : NULL;
		ft_putstr_fd(item->str, 1);
	}
	else
		ft_putstr_fd(item->str, 1);
	ft_putstr_fd(tgetstr("me", NULL), 1);
}

void			ft_print_all(t_window *size, t_clist **list)
{
	t_clist	*lst;
	int		i;
	int		start;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	i = print_header(size);
	start = ft_fill_struct_window(size, list);
	lst = *list;
	if (start > 2 * size->li)
	  while (--start > 0)
	    lst = lst->next;
	while (lst->next != NULL && size->tab_counter < size->co)
	{
		ft_print_item(lst);
		size->arg_printed++;
		if (size->arg_printed + 1 > size->li)
		{
			size->tab_counter += size->max_len + 2;
			size->arg_printed = 0;
		}
		ft_putstr_fd(tgoto(GET_CM, size->tab_counter - 1,
					size->arg_printed + i), 1);
		lst = lst->next;
	}
	//	ft_print_item(lst);
}
