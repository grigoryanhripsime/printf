CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCS)

SRCS = ft_printf.c print_char.c print_str.c print_int.c print_hex.c print_address.c print_unsigned_int.c

INCS = ./

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
