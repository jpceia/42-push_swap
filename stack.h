/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:20:04 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 05:24:25 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
}	t_stack;

void	stack_print(t_stack *stack);
size_t	stack_len(t_stack *stack);
int		stack_top(t_stack *stack);
void	stack_clear(t_stack *stack);
int		*stack_array(t_stack *stack);

void	stack_swap(t_stack **stack_ref);
void	stack_rotate(t_stack **stack_ref);
void	stack_reverse_rotate(t_stack **stack_ref);
t_stack	*stack_push(t_stack **stack_ref, int value);
int		stack_pop(t_stack **stack_ref);

int		stack_at(t_stack *stack, size_t pos);
int		stack_argmax(t_stack *stack);
int		stack_argmin(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);

int		stack_is_sorted(t_stack *stack);
t_stack	*stack_push_array(t_stack **stack, int *arr, size_t N);

#endif
