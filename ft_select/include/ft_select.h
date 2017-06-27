/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:26:11 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 13:02:14 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

# define X size->tab_counter
# define Y size->arg_printed
# define GET_CM tgetstr("cm", NULL)
# define FD 3
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"
# define LINE1 "/* ******************************************************* */\n"
# define LINE2 "/*                                                         */\n"
# define LINE3 "/*                                       :::      :::::::: */\n"
# define LINE4 "/*   ft_select                         :+:      :+:    :+: */\n"
# define LINE5 "/*                                   +:+ +:+         +:+   */\n"
# define LINE6 "/*                                 +#+  +:+       +#+      */\n"
# define LINE7 "/*                               +#+#+#+#+#+   +#+         */\n"
# define LINE8 "/*   Created by vhuylebr              #+#    #+#           */\n"
# define LINE9 "/*                                   ###   ########.fr     */\n"
# define LINEA "/*                                                         */\n"
# define LINEB "/* ******************************************************* */\n"

typedef struct		s_window
{
	int				li;
	int				co;
	int				num_tab;
	int				max_len;
	int				arg_printed;
	int				listcount;
	int				items_per_tab;
	int				tab_counter;
}					t_window;

typedef struct		s_clist
{
	char			*str;
	struct s_clist	*next;
	struct s_clist	*prev;
	int				is_selected;
	int				is_cursor;
}					t_clist;

/*
** print_header.h
*/

int					print_header(t_window *size);

/*
** main.c
*/

int					ft_set_term(struct termios *term);
int					ft_get_size(t_window *size);
int					ft_unset_term(struct termios *term);

/*
** move.c
*/

t_clist				*ft_move_up(t_window *size, t_clist **list,
	t_clist *cursor);
t_clist				*ft_move_down(t_window *size,
		t_clist **list, t_clist *cursor);
t_clist				*ft_move_left(t_window *size,
		t_clist **list, t_clist *cursor);
t_clist				*ft_move_right(t_window *size,
		t_clist **list, t_clist *cursor);
t_clist				*go_to_letter(char c, t_window *size,
		t_clist **list, t_clist *cursor);

/*
** key.c
*/

int					is_arrow(char *buf);
int					is_space(char *buf);
int					is_bspace(char *buf);
int					is_del(char *buf);

/*
** select_del_list.c
*/

void				ft_refresh(t_window *size,
		t_clist **list, struct termios *term);
t_clist				*what_arrow(int drctn, t_window *size,
		t_clist **list, t_clist *cursor);
t_clist				*ft_select(t_window *size, t_clist **list, t_clist *cursor);
t_clist				*ft_del_cursor(t_window *size, t_clist **list,
	t_clist *cursor);

/*
** key2.c
*/

int					is_return(char *buf);
int					is_esc(char *buf);
int					is_cntrl_z(char *buf);
int					is_ctrl_c(char *buf);
int					is_sig(char *buf);

/*
** print2.c
*/

int					ft_maxlen(t_clist **list);

/*
** signal.c
*/

void				ft_signals();

/*
** ft_print_all.c
*/

void				ft_print_all(t_window *size, t_clist **list);

/*
** listfunctions.c
*/

int					ft_list_del(t_clist **alst);
void				ft_clstadd(t_clist **alst, t_clist *new);
t_clist				*ft_clstnew(char *str);
void				ft_clstaddend(t_clist **alst, t_clist *new);
int					ft_clistcount(t_clist **alst);

/*
** libc
*/

void				ft_putstr_fd(char *s, int fd);
char				*ft_strdup(char *str);
int					ft_strlen(char *str);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t len);

/*
** listfunctions2.c
*/

t_clist				*ft_del_lst_cursor(t_clist **list, t_clist *cursor);
t_clist				*ft_del_cursor(t_window *size, t_clist **list,
	t_clist *cursor);
t_clist				*list_end(t_clist *cursor);
t_clist				*list_start(t_clist *cursor);

t_clist				*ft_del_start_end(t_clist **old, t_clist *cursor);
#endif
