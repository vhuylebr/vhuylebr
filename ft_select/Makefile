CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wall -Werror -Wextra -I include/

NAME	=	ft_select

SRCS	= main.c \
		signal.c \
	fc_list.c \
	fc_list2.c \
	ft_strdup.c \
	ft_strlen.c \
	print.c \
	print2.c \
	ft_putstr_fd.c \
	ft_strnew.c \
	ft_bzero.c \
	key.c \
	key2.c \
	delete_select_list.c \
	moves.c \
	header42.c \
	term.c \
	bonus_letter.c

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
