#ifndef DOUBLE_STACK
# define DOUBLE_STACk

# include "libft.h"
# include "stack.h"

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

void double_stack_print(t_stack *a, t_stack *b);
void double_stack_init(t_stack **a, t_stack **b);
void operation_pa(t_stack **a, t_stack **b);
void operation_pb(t_stack **a, t_stack **b);
void operation_sa(t_stack **a, t_stack **b);
void operation_sb(t_stack **a, t_stack **b);
void operation_ss(t_stack **a, t_stack **b);
void operation_ra(t_stack **a, t_stack **b);
void operation_rb(t_stack **a, t_stack **b);
void operation_rr(t_stack **a, t_stack **b);
void operation_rra(t_stack **a, t_stack **b);
void operation_rrb(t_stack **a, t_stack **b);
void operation_rrr(t_stack **a, t_stack **b);

#endif