#include "push_swap.h"

void print_stack(t_stack *head)
{
    while (head)
    {
        printf("%d\n", head->num);
        head = head->next;
    }
}

int main(int argc, const char *argv[])
{
    t_list *stack;

    if (argc < 2)
        return 1;
    parsing(argv + 1);
    stack = init_stack();
    fill_stack(argv + 1, &stack);
    if (check_doubles(stack->stack_a) == -1)
    {
        free_mem(&stack);
        free(stack);
        err_msg();
    }

    print_stack(stack->stack_a);
    do_sa(&(stack->stack_a));

    free_mem(&stack);
    free(stack);
    exit(0);
    return 0;
}