NAME=libft.a
FLAGS=-Wall -Wextra -Werror
CC=gcc
HDRS=libft.h
SRCS=ft_atoi.c ft_memtools.c ft_strchr.c ft_strmapi.c \
ft_bzero.c ft_putchar.c ft_strdup.c ft_strtools.c \
ft_calloc.c ft_putnbr.c ft_striteri.c ft_strtrim.c \
ft_checkcase.c ft_split.c ft_strjoin.c ft_substr.c \
ft_strstr.c ft_strcmp.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all