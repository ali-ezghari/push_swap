#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int num;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_list
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;
} t_list;

void ft_putstr(char *str);
long ft_atol(const char *str);

void parsing(const char *av[]);
int check_doubles(t_stack *stack);
void err_msg(void);

t_list *init_stack();
t_stack *create_node(int data);
void fill_stack(int argc, const char *argv[], t_list **stack);
void free_mem(t_list **stack);

void do_pa(t_stack **stack_a, t_stack **stack_b);
void do_pb(t_stack **stack_a, t_stack **stack_b);

void do_sa(t_stack **stack_a);
void do_sb(t_stack **stack_b);
void do_ss(t_stack **stack_a, t_stack **stack_b);

void do_ra(t_stack **stack_a);
void do_rb(t_stack **stack_b);
void do_rr(t_stack **stack_a, t_stack **stack_b);

void do_rra(t_stack **stack_a);
void do_rrb(t_stack **stack_b);
void do_rrr(t_stack **stack_a, t_stack **stack_b);

void sort_two_nums(t_stack **stack_a);
void sort_three_nums(t_stack **stack_a);
void sort_four_nums(t_stack **stack_a, t_stack **stack_b);
void sort_five_nums(t_stack **stack_a, t_stack **stack_b);

// void large_sort(t_list **stack);
// int *FromStackToArray(t_list *stack);

int ft_min(t_stack *stack);
int ft_max(t_stack *stack);
int *insertion_sort(int arr[], int size);

int is_sorted(t_stack *stack_a);
void ft_swap(t_list **stack);
#endif
