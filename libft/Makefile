SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_memcpy.c ft_bzero.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memchr.c ft_memcmp.c \
	  ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c \
	  ft_strtrim.c ft_split.c
SRCB = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
	   ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_O = $(SRC:.c=.o)
SRCB_O = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)

bonus : $(SRCB_O)
	ar rc $(NAME) $(SRCB_O)

clean:
	rm -f $(SRC_O) $(SRCB_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
.SECONDARY : $(SRC_O) $(SRCB_O)
