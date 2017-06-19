/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:49:45 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 19:54:47 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>

# define ECHO "echo"
# define NO_HOME "cd: No HOME found"
# define SETENV		"setenv"
# define UNSETENV		"unsetenv"
# define EXIT		"exit"
# define CD		"cd"
# define ENV		"env"
# define HOME		"~/"
# define PROMPT		"minishell"
# define PROMPT2		"42sh> "
# define CTRLC		"\nUSER> "
# define NOT_DIR		"Not a directory."
# define NOT_FOUND	"No such file or directory."
# define NO_PERMISSION	"Permission denied."
# define SEGF_DUMP	"Segmentation fault (core dumped)"
# define SEGF_NO_DUMP	"Segmentation fault"
# define FLOAT_DUMP	"Floating exception (core dumped)"
# define FLOAT_NO_DUMP	"Floating exception"
# define BAD_COM		"Command not found."
# define EXEC_ERROR	"Exec format error. Binary file not executable."
# define SETENV_ERR	"setenv: Too much argument."
# define UNSETENV_ERR	"unsetenv: Too few argument."
# define ALPHANUM_SETENV	"setenv: Variable name must contain alphanumeric"

typedef	struct	s_minishell
{
	char		*s;
	char		**str;
	int			i;
	int			k;
}				t_minishell;

typedef struct	s_cd_back
{
	char		*tmp;
	char		buff[1000];
}				t_cd_back;

/*
** bonus_cd.c
*/

char			**bonus_cd(DIR *dir, char *path, char **env);
int				cd_u(char *av, char **env, int pwd, int old);
/*
** sift.c
*/

void			sigft(int signal, char **env);

/*
** ft_putnbr_fd.c
*/

void			ft_putnbr_fd(int n, int fd);

/*
** ft_printf.c
*/

int				ft_printf(int fd, char *str, int ret, ...);
void			ft_putchar_fd(char c, int fd);

/*
**ft_echo.c
*/

int				ft_echo(char **s);

/*
** ft_strnew.c
*/

char			ft_strnew(int len);

/*
**redirection.c
*/

int				search_double_redir(char **s);
void			double_redirection(char **s, char **envcpy, char **path, int y);
int				redirection(char **s, char **envcpy, char **path, int y);
int				search_simple_redirection(char **s);
int				redirection_exe(char **path, char **s, char **envcpy, int fd);

/*
** my_parseur
*/

int				count_parse(char *str);
char			**my_parseur(char *str, int mot, int i);

/*
** my_strsplit.c
*/

int				ft_n(const char *str, char c, int i, int w);
char			**my_strsplit2(char *str, char c, int mot, int i);

/*
**utils.c
*/

int				my_strncmp(char *s1, char *s2, int n);
int				my_strcmp(char *s1, char *s2);
char			*strjoin(char const *s1, char const *s2);
char			*strnew(size_t size);
int				aff_tab(char **str, int newline);

/*
**ft_putstr.c
*/

void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			**unmatched(void);
void			ft_putstr_fd(char *str, int fd);

/*
**my_cd.c
*/

int				my_cd(char **av, char **env);
int				cd_normal(char *av, char **env, int ref_pwd, int ref_oldpwd);

/*
**fonction for env
*/

char			*ft_getenv_no_malloc(char **env, char *to_find);
int				find_in_env(char **env, char *to_find);
char			*ft_getenv(char **env, char *to_find);

/*
**main.c
*/

int				len(char *str);
int				next_check(char **s, char ***envcpy, int y);
void			print_prompt(char **env);

/*
** fc_env.c
*/

int				add_env(char **envcpy, char **s);
int				remove_env(char **envcpy, char **s);
int				line_28(char **envcpy);

/*
** execution.c
*/

int				exe_file(char **s, char **envcpy);
int				exe(char **s, char ***envcpy, int i, int k);

/*
**double_strcpy.c
*/

char			**tab_cpy(char **tab);
char			**double_strcpy(char **env);
char			**free_tab(char **tab, char **en);
int				find(char **envcpy, char *str);

/*
** change.c
*/

void			change(char **s, int x, int y);
void			change2(char **s, int x, int y);

#endif
