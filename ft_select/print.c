/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:18:06 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 12:58:35 by vhuylebr         ###   ########.fr       */
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
	t_clist	*tmp;
	int		i;

	i = 1;
	ft_get_size(size);
	size->tab_counter = 1;
	size->arg_printed = 0;
	//size->num_tab = num_col_needed(size, list);
	size->max_len = ft_maxlen(list);
	//size->lsts_per_tab = size->listcount / size->num_tab + 1;
	if (size->co <= (size->max_len + 2) * size->num_tab)
	{
		tmp = *list;
		while (tmp->is_cursor == 0)
		{
			++i;
			tmp = tmp->next;
		}
		return ((i / size->li * size->li) - ((i / size->li * size->li) %
					(size->co / (size->max_len + 2) * size->li)));
	}
	return (0);
}

void			ft_print_lst(t_clist *cursor)
{
	struct stat	filestat;

	if (cursor->is_cursor)
		ft_putstr_fd(tgetstr("us", NULL), FD);
	if (cursor->is_selected)
		ft_putstr_fd(tgetstr("mr", NULL), FD);
	if (lstat(cursor->str, &filestat) >= 0)
	{
		ft_putstr_fd(C_BOLD, FD);
		S_ISBLK(filestat.st_mode) ? ft_putstr_fd(C_RED, FD) : NULL;
		S_ISCHR(filestat.st_mode) ? ft_putstr_fd(C_BLUE, FD) : NULL;
		S_ISDIR(filestat.st_mode) ? ft_putstr_fd(C_CYAN, FD) : NULL;
		S_ISFIFO(filestat.st_mode) ? ft_putstr_fd(C_BROWN, FD) : NULL;
		S_ISLNK(filestat.st_mode) ? ft_putstr_fd(C_GREEN, FD) : NULL;
		S_ISSOCK(filestat.st_mode) ? ft_putstr_fd(C_MAGENTA, FD) : NULL;
		ft_putstr_fd(cursor->str, FD);
	}
	else
		ft_putstr_fd(cursor->str, FD);
	ft_putstr_fd(tgetstr("me", NULL), FD);
}

void			ft_print_all(t_window *size, t_clist **list)
{
	t_clist	*lst;
	int		i;
	int		start;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), FD);
	i = print_header(size);
	start = ft_fill_struct_window(size, list);
	lst = *list;
	while (--start > 0)
		lst = lst->next;
	while (lst != NULL && size->tab_counter + size->max_len + 2 < size->co)
	{
		ft_print_lst(lst);
		size->arg_printed++;
		if (size->arg_printed + 1 > size->li)
		{
			size->tab_counter += size->max_len + 2;
			size->arg_printed = 0;
		}
		ft_putstr_fd(tgoto(GET_CM, size->tab_counter - 1,
					size->arg_printed + i), FD);
		lst = lst->next;
	}
}
