NAME = push_swap.a

SRCS =	$(wildcard *.c)

BNS_SRCS = checker.c

OBJS :=$(SRCS:.c=.o)

BNS_OBJS :=$(BNS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all tester bonus clean fclean runner re

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	mv ./libft/libft.a .
	ar rc $(NAME) libft.a $(OBJS)
	ranlib $(NAME)

runner:
	gcc -Wall -Werror -Wextra -o push_swap *.c
	mv push_swap ./push_swap_visualizer-master/build
	cd ./push_swap_visualizer-master/build && ./bin/visualizer

tester: $(SRCS)
	cc $(CFLAGS) $(SRCS)

bonus:
	make re -C libft
	mv ./libft/libft.a .
	cc $(CFLAGS) ps_counters.c ps_operations.c ps_operations_2.c \
	ps_operations_3.c ps_sorting.c ps_utils.c $(BNS_SRCS) libft.a
clean:
	rm -f a.out
	rm -f libft.a
	rm -f $(OBJS)
	cd libft && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
