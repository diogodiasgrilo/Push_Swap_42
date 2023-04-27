NAME = push_swap

SRCS =	./srcs/ps_split.c \
		./srcs/push_swap.c \
		./srcs/ps_utils.c \
		./srcs/ps_exits.c \
		./srcs/ps_errors.c \
		./srcs/ps_sorting.c \
		./srcs/ps_operations_1.c \
		./srcs/ps_operations_2.c \
		./srcs/ps_operations_3.c \
		./srcs/ps_move_cutters.c \
		./srcs/ps_final_chapter.c \

BNS_SRCS = ./srcs/bonus/checker.c \
			./srcs/bonus/ps_b_sorting.c \
			./srcs/bonus/ps_bonus_utils.c \
			./srcs/bonus/ps_b_erros.c \
			./srcs/bonus/ps_b_exits.c \
			./srcs/bonus/ps_b_moves.c \
			./srcs/ps_operations_1.c \
			./srcs/ps_operations_2.c \
			./srcs/ps_operations_3.c \
			./srcs/ps_split.c \

OBJS :=$(SRCS:.c=.o)

BNS_OBJS :=$(BNS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "$(GREEN)Bada-bing...push_swap MADE!$(DEFAULT)"

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize=address

runner:
	@cc -Wall -Werror -Wextra $(SRCS) -o push_swap
	@mv push_swap ./push_swap_visualizer-master/build
	@cd ./push_swap_visualizer-master/build && ./bin/visualizer

tester: $(SRCS)
	cc $(CFLAGS) $(SRCS)

bonus:
	cc $(CFLAGS) $(BNS_SRCS) -o checker -fsanitize=address
	@echo "$(GREEN)There's the bonus, DONE!$(DEFAULT)"

clean:
	@rm -f $(OBJS)
	@rm -f ./bonus/$(BNS_OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@echo "$(ORANGE)Cleanup...done!$(DEFAULT)"

re: fclean all

.PHONY: all tester bonus clean fclean runner re

#COLORS                                                                         
GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[38;5;208m
DEFAULT = \033[0m
YELLOW = \033[1;33m
