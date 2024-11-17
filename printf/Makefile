SRC = ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
  ar rc $(NAME) $(SRC_O)

%.o: %.c
  $(CC) $(CFLAGS) -c $< -o $@


clean:
  rm -f $(SRC_O)

fclean: clean
  rm -f $(NAME)

re: fclean all