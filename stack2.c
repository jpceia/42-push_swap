#include "stack.h"
#include <stdlib.h>

void    stack_swap(t_stack **stack)
{
    t_stack *node;

    node = (*stack)->prev;
    if (node == NULL)
        return ;
    (*stack)->prev = node->prev;
    node->prev = *stack;
    *stack = node;
}

void    stack_rotate(t_stack **stack)
{
    t_stack *it;
    t_stack *first;

    if (*stack == NULL)
        return ;
    first = *stack;
    *stack = first->prev;
    first->prev = NULL;
    it = *stack;
    while (it->prev)
        it = it->prev;
    it->prev = first;
}

void    stack_reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *next_last;

    if (*stack == NULL)
        return ;
    last = *stack;
    while (last->prev)
    {
        next_last = last;
        last = last->prev;
    }
    next_last->prev = NULL;
    last->prev = *stack;
    *stack = last;
}

void    stack_push(t_stack **stack, int value)
{
    t_stack *node;
    
    node = malloc(sizeof(*stack));
    node->value = value;
    node->prev = *stack;
    *stack = node;
}

int     stack_pop(t_stack **stack)
{
    t_stack *node;
    int res;

    node = *stack;
    res = node->value;
    *stack = node->prev;
    free(node);
    return (res);
}

int     stack_top(t_stack *stack)
{
    return (stack->value);
}