#include "checker.h"

int	is_sorted(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	while (stack_a->next != NULL)
	{
		if (stack_a->num > stack_a->next->num)
		{
			return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
