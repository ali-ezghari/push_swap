/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:06:17 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:06:19 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
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

char	**ft_split(const char *str, char sep);
char	*ft_strjoin(char *line, const char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
long	ft_atol(char *str);
t_stack	*create_node(int data);
void	free_mem(t_list **stack, char **arr);
void	err_msg(t_list **stack, char **arr);
void	ft_putstr(char *str);
char	*ft_strdup(char *s);

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

int		parsing(char **arr);
int		check_doubles(t_stack *stack);
int		white_spaces(const char *str);
int		empty_check(const char **argv);
int		is_sorted(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);
void	free_arr(char **arr);

#endif
