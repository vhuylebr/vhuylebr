/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:49:45 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/08 16:28:20 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include <string.h>
#include <stdio.h>

# define NO_HOME "cd: No HOME found"
# define SETENV		"setenv"
# define UNSETENV		"unsetenv"
# define EXIT		"exit"
# define CD		"cd"
# define ENV		"env"
# define HOME		"~/"
# define PROMPT		"42sh"
# define PROMPT2		"42sh> "
# define CTRLC		"\n42sh> "
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

typedef struct s_cd
{
	char *old;
	char *new;
}               t_cd;

/* ft_strnew.c */
char	ft_strnew(int len);

/* redirection.c */
int	search_double_redir(char **s);
void	double_redirection(char **s, char **envcpy, char **PATH, int y);
int		redirection(char **s, char **envcpy, char **PATH, int y);
int	search_simple_redirection(char **s);
int	redirection_exe(char **PATH, char **s, char **envcpy, int fd);

/* my_parseur */
int		count_parse(char *str);
char	**my_parseur(char *str, int mot, int i);

/* my_strsplit.c */
int		ft_n(const char *str, char c);
char	**my_strsplit2(char *str, char c, int mot, int i);

/* utils.c */
int	my_strncmp(char *s1, char *s2, int n);
int	my_strcmp(char *s1, char *s2);
char	*strjoin(char const *s1, char const *s2);
char	*strnew(size_t size);

/* my_cd.c */
int	my_cd(char **av, char **env, int ref);

/* main.c */
int	len(char *str);
int	next_check(char **s, char ***envcpy, int y);

/* fc_env.c */
int	add_env(char **envcpy, char **s);
int	remove_env(char **envcpy, char **s);
int	line_28(char **envcpy);

/* execution.c */
int	exe_file(char **s, char **envcpy);
int	exe(char **s, char ***envcpy, int i, int k);

/* double_strcpy.c */
char	**tab_cpy(char **tab);
char	**double_strcpy(char **env);
char	**free_tab(char **, char **);
int	find(char **envcpy, char *str);

/* change.c */
void	change(char **s, int x, int y);
void	change2(char **s, int x, int y);

#endif /* !MINISHELL_H_ */
