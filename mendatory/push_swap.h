/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:05:47 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/15 21:06:53 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
	int				size;
}					t_list;

void	ft_putstr(char *str);
long	ft_atol(const char *str);

int		parsing(char **arr);
int		check_doubles(t_stack *stack);
void	err_msg(t_list **stack, char **arr);

t_list	*init_stack(void);
t_stack	*create_node(int data);
void	fill_stack(char **arr, t_list **stack);
void	ft_push_swap(t_list **stack, char **arr);

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

void	sort_two_nums(t_stack **stack_a);
void	sort_three_nums(t_stack **stack_a);
void	sort_four_nums(t_stack **stack_a, t_stack **stack_b);
void	sort_five_nums(t_stack **stack_a, t_stack **stack_b);
void	large_sort(t_list **stack);

int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
int		*bubble_sort(int arr[], int size);
int		*create_sort_array(t_list *stack);
int		is_sorted(t_stack *stack_a);
int		ft_lstsize(t_stack *stack);
int		get_end(int size);

char	*ft_strdup(const char *s);
char	**ft_split(char *str, char sep);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_mem(t_list **stack, char **arr);
void	free_arr(char **arr);
int		white_spaces(const char *str);

#endif
