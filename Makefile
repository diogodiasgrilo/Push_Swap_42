NAME = push_swap.a

SRCS =	$(wildcard *.c)

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all tester clean fclean re

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

tester: $(SRCS)
	make -C libft
	cc $(CFLAGS) $(SRCS) libft/libft.a
clean:
	rm -f ./libft/*.o
	rm -f a.out
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all
