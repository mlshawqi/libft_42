SRC = 
SRCB = 

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_O = $(SRC:.c=.o)
SRCB_O = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
    ar rc $(NAME) $(SRC_O)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

bonus : $(SRCB_O)
    ar rc $(NAME) $(SRCB_O)

clean:
    rm -f $(SRC_O) $(SRCB_O)

fclean: clean
    rm -f $(NAME)

re: fclean all bonus