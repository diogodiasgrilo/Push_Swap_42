NAME = push_swap.a

SRCS =	push_swap.c \
		ps_utils.c \
		ps_utils2.c \
		ps_sorting.c \
		ps_operations_1.c \
		ps_operations_2.c \
		ps_operations_3.c \
		ps_move_cutters.c \
		ps_final_chapter.c \

BNS_SRCS = checker.c \
			ps_bonus_utils.c \
			ps_bonus_utils2.c \

OBJS :=$(SRCS:.c=.o)

BNS_OBJS :=$(BNS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all tester bonus clean fclean runner re

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

runner:
	cc -Wall -Werror -Wextra $(SRCS) -o push_swap
	mv push_swap ./push_swap_visualizer-master/build
	cd ./push_swap_visualizer-master/build && ./bin/visualizer

tester: $(SRCS)
	cc $(CFLAGS) $(SRCS)

bonus:
	cc $(CFLAGS) ps_counters.c ps_operations_1.c ps_operations_2.c \
	ps_operations_3.c ps_sorting.c ps_utils.c $(BNS_SRCS) libft.a
clean:
	rm -f a.out
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
