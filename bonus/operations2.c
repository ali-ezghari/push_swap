
#include "checker.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (!stack || !stack->next)
	{
		return ;
	}
	tmp = stack->next->num;
	stack->next->num = stack->num;
	stack->num = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
