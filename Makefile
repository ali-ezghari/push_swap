CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c parsing.c init.c swap_op.c push_op.c rotate_op.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re