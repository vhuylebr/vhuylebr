##
## Makefile for mm in /home/vhuylebr/Desktop/PSU_2016_minishell1
##
## Made by valerian huylebroeck
## Login   <vhuylebr@epitech.net>
##
## Started on  Mon Jan  9 19:08:44 2017 valerian huylebroeck
## Last update Thu May 18 09:36:08 2017 valerian huylebroeck
##

CC	=	gcc -g

RM	=	rm -f

CFLAGS	+=	-Wall -Werror -Wextra -I include/

NAME	=	42sh

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
		src/ft_strnew.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
