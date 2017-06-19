# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/14 17:18:06 by vhuylebr          #+#    #+#              #
#    Updated: 2017/06/16 20:36:32 by vhuylebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc -g3

RM	=	rm -f

CFLAGS	+=	-Wall -Werror -Wextra -I include/

NAME	=	minishell

SRCS	=	src/get_next_line.c	\
		src/my_cd.c		\
		src/utils.c		\
		src/double_strcpy.c	\
		src/my_strsplit.c		\
		src/main.c		\
		src/fc_env.c		\
		src/change.c		\
		src/execution.c		\
		src/redirection.c	\
		src/ft_strnew.c		\
		src/lib_env.c		\
		src/ft_putstr.c		\
		src/ft_echo.c		\
		src/sigft.c			\
		src/ft_printf.c		\
		src/ft_putnbr_fd.c	\
		src/bonus_cd.c		\
		src/print_prompt.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
