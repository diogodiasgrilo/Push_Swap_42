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
	cc $(CFLAGS) $(SRCS)
clean:
	rm -f a.out
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
