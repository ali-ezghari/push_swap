#include "push_swap.h"

int main(int argc, const char *argv[])
{
    t_list *stack;

    if (argc < 2)
        return 1;
    parsing(argv + 1);
    stack = init_stack();
    if (!stack)
    {
        exit(1); 
    }
    fill_stack(argc, argv, &stack);
    ft_swap(&stack);
    free_mem(&stack);
    return 0;
}
