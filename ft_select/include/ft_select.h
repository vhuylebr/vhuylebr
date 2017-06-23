#ifndef FT_SELECT_H

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
# define TPUTS_END 1, tputs_putchar
# define FD 2

typedef struct  s_window
{
  int     li;
  int     co;
  int     num_tab;
  int     max_len;
  int     arg_printed;
  int     listcount;
  int     items_per_tab;
  int     tab_counter;
}                               t_window;

typedef struct          s_clist
{
  char                    *str;
  struct s_clist  *next;
  struct s_clist  *prev;
  int                             is_selected;
  int                             is_cursor;
}                                       t_clist;

/* main.c */
int             ft_set_stage(struct termios *term);
int             ft_get_size(t_window *size);
int             ft_unset_stage(struct termios *term);
/* move.c*/
t_clist *ft_move_up(t_window *size, t_clist **list, t_clist *item);
t_clist *ft_move_down(t_window *size, t_clist **list, t_clist *item);
t_clist *ft_move_left(t_window *size, t_clist **list, t_clist *item);
t_clist *ft_move_right(t_window *size, t_clist **list, t_clist *item);

/* key.c */
int             is_arrow(char *buf);
int             is_space(char *buf);
int             is_bspace(char *buf);
int             is_del(char *buf);

int             is_alt_r(char *buf);
int             is_cntrl_c(char *buf);
int             is_cntrl_z(char *buf);
int             is_esc(char *buf);
int             is_rtn(char *buf);

/* select_del_list.c */
void    ft_refresh(t_window *size, t_clist **list, struct termios *term);
t_clist *what_arrow(int drctn, t_window *size, t_clist **list, t_clist *item);
t_clist *ft_select(t_window *size, t_clist **list, t_clist *item);
t_clist *ft_del_item(t_window *size, t_clist **list, t_clist *item);

/* key2.c */
int             is_rtn(char *buf);
int             is_esc(char *buf);
int             is_cntrl_z(char *buf);
int             is_cntrl_c(char *buf);
int             is_alt_r(char *buf);

/* print2.c */
int             ft_maxlen(t_clist **list);
int             tputs_putchar(int c);

/* signal.c */
void ft_signals();

/* ft_print.c */
void    ft_print(t_window *size, t_clist **list);

/* listfunctions.c */
int             ft_list_del(t_clist **alst);
void    ft_clstadd(t_clist **alst, t_clist *new);
t_clist *ft_clstnew(char *str);
void    ft_clstaddend(t_clist **alst, t_clist *new);
int             ft_clistcount(t_clist **alst);

/* libc */
void    ft_putstr_fd(char *s, int fd);
char *ft_strdup(char *str);
int ft_strlen(char *str);
char    *ft_strnew(size_t size);
void    ft_bzero(void *s, size_t len);

/* listfunctions2.c */
t_clist *ft_del_lst_item(t_clist **list, t_clist *item);
t_clist *ft_del_item(t_window *size, t_clist **list, t_clist *item);
t_clist *list_end(t_clist *item);
t_clist *list_start(t_clist *item);

t_clist *ft_del_start_end(t_clist **old, t_clist *item);
#endif /*FT_SELECT_H*/
