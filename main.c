#include "push_swap.h"

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->num);
        stack = stack->next;
    }
}
int main(int argc, const char *argv[])
{
    t_list *stack;

    if (argc < 2)
        return 1;
    parsing(argv + 1);
    stack = init_stack();
    fill_stack(argc, argv, &stack);
    // exit(0);
    ft_swap(&stack);
    // print_stack(stack->stack_a);
    free_mem(&stack);
    return 0;
}
