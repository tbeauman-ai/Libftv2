NAME=libft.a
FLAGS=-Wall -Wextra -Werror
CC=gcc
HDRS=libft.h
SRCS=ft_atoi.c ft_memtools.c ft_strchr.c ft_strmapi.c \
ft_bzero.c ft_putchar.c ft_strdup.c ft_strtools.c \
ft_calloc.c ft_putnbr.c ft_striteri.c ft_strtrim.c \
ft_checkcase.c ft_split.c ft_strjoin.c ft_substr.c \
ft_strstr.c ft_strcmp.c ft_switchcase.c
BONUS=ft_list_utils_bonus.c ft_list_free_utils_bonus.c ft_listiter_bonus.c
ALLSRCS=$(SRCS) $(BONUS)
OBJS=$(SRCS:.c=.o)
ALLOBJS=$(ALLSRCS:.c=.o)

all: $(NAME)

bonus: $(ALLOBJS)
	ar rc $(NAME) $(ALLOBJS)
	ranlib $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -rf $(ALLOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all