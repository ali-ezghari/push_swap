
#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_list;

char	*get_next_line(int fd);

char	**ft_split(char *str, char sep);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_strchr(char *s, int c);
long	ft_atol(const char *str);
t_stack	*create_node(int data);
void	free_mem(t_list **stack, char **arr);
void	err_msg(t_list **stack, char **arr);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s);

t_list	*init_stack(void);
void	fill_stack(char **arr, t_list **stack);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

int	parsing(char **arr);
int	check_doubles(t_stack *stack);
int	white_spaces(const char *str);
int	empty_check(const char **argv);
int is_sorted(t_stack *stack);
#endif
