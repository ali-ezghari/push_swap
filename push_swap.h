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

void	ft_putstr(char *str);
long ft_atol(const char *str);

void parsing(const char *av[]);
int check_doubles(t_stack *stack);
void err_msg(void);


t_list *init_stack();
t_stack *create_node(int data);
void fill_stack(const char *argv[], t_list **stack);
void free_mem(t_list **stack);

void push(t_stack **from, t_stack **to);
void swap(t_stack *stack);

void do_sa(t_stack **stack_a);
void do_sb(t_stack **stack_b);
void do_ss(t_stack **stack_a, t_stack **stack_b);
#endif