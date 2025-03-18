
GREEN = \033[0;32m
GREEN_CHECK = \033[32m✅\033[0m
RED = \033[0;31m
RESET = \033[0m


CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = mendatory/main.c mendatory/utils.c mendatory/parser.c mendatory/init.c mendatory/swap_op.c mendatory/push_op.c mendatory/rotate_op.c mendatory/reverse_rotate.c mendatory/sort.c mendatory/utils2.c mendatory/ft_swap.c mendatory/sort_utils.c mendatory/sort2.c mendatory/ft_split.c mendatory/ft_strjoin.c
SRCSB = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/init_bonus.c bonus/operations1.c bonus/operations2.c bonus/operations3.c bonus/operations4.c bonus/parser_bonus.c bonus/ft_split.c bonus/utils1.c bonus/utils2.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = push_swap
NAMEB = checker

all: $(NAME)
bonus: $(NAMEB)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $< $(GREEN_CHECK)$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Mandatory: $(NAME) was created $(GREEN_CHECK)$(RESET)"

$(NAMEB): $(OBJSB)
	@$(CC) $(FLAGS) $(OBJSB) -o $(NAMEB)
	@echo "$(GREEN)Bonus: $(NAME) was created $(GREEN_CHECK)$(RESET)"

clean:
	@rm -f $(OBJS) $(OBJSB)
	@echo "$(RED)Removing object files...$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAMEB)
	@echo "$(RED)Removing $(NAME) And $(NAMEB)...$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus