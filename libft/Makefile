NAME = libft.a

SRCS =	$(wildcard *.c)
BONUS_SRC = $(wildcard bonus/*.c)

OBJS :=$(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

