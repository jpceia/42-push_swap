#include "double_stack.h"

void operation_ra(t_stack **a, t_stack **b)
{
    (void)b;

    ft_putstr_fd("ra\n", STDOUT_FILENO);
    stack_rotate(a);
}

void operation_rb(t_stack **a, t_stack **b)
{
    (void)a;

    ft_putstr_fd("rb\n", STDOUT_FILENO);
    stack_rotate(b);
}

void operation_rr(t_stack **a, t_stack **b)
{
    ft_putstr_fd("rr\n", STDOUT_FILENO);
    stack_rotate(a);
    stack_rotate(b);
}

void operation_rra(t_stack **a, t_stack **b)
{
    (void)b;

    ft_putstr_fd("rra\n", STDOUT_FILENO);
    stack_reverse_rotate(a);
}

void operation_rrb(t_stack **a, t_stack **b)
{
    (void)a;

    ft_putstr_fd("rrb\n", STDOUT_FILENO);
    stack_reverse_rotate(b);
}

void operation_rrr(t_stack **a, t_stack **b)
{
    ft_putstr_fd("rrr\n", STDOUT_FILENO);
    stack_reverse_rotate(a);
    stack_reverse_rotate(b);
}