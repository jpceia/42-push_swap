#include "stack.h"
#include "libft.h"

void    stack_print(t_stack *stack)
{
    while (stack)
    {
        ft_putnbr_fd(stack->value, STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO);
        stack = stack->prev;
    }

    ft_putstr_fd("____\n", STDOUT_FILENO);
}

size_t  stack_len(t_stack *stack)
{
    size_t len;
    
    len = 0;
    while (stack)
    {
        len++;
        stack = stack->prev;
    }
    return (len);
}

int stack_is_sorted(t_stack *stack)
{
    if (stack == NULL)
        return (1);
    while (stack->prev)
    {
        if (stack->value > stack->prev->value)
            return (0);
        stack = stack->prev;
    }
    return (1);
}

void    stack_clear(t_stack **stack)
{
    t_stack *node;
    t_stack *prev_node;

    node = *stack;
    while (node->prev)
    {
        prev_node = node->prev;
        free(node);
        node = prev_node;
    }
    free(node);
    //free(stack);
}