# -*- Makefile -*-
CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_puthexa.c ft_printf.c ft_itoa_u.c
OBJS = $(SRC:.c=.o)

$(NAME) = $(OBJS)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

%.o:%.c
	$(CC) -Ilibft -I. $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
