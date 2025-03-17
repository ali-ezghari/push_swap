CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c parser.c init.c swap_op.c push_op.c rotate_op.c reverse_rotate.c sort.c utils2.c ft_swap.c sort_utils.c sort2.c ft_split.c ft_strjoin.c
SRCSB = checker.c get_next_line.c get_next_line_utils.c init_bonus.c operations1.c operations2.c operations3.c operations4.c parser_bonus.c ft_split.c ft_strjoin.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJSB)
	$(CC) $(FLAGS) $(OBJSB) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus