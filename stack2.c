/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:23:35 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 00:35:06 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

/*
 * Swaps the first two elements at the top of the stack
 * If the stack has no or only one elements (stack == NULL
 * or stack->prev == NULL) then do nothing
 */
void	stack_swap(t_stack **stack)
{
	t_stack	*node;

	if (*stack == NULL)
		return ;
	node = (*stack)->prev;
	if (node == NULL)
		return ;
	(*stack)->prev = node->prev;
	node->prev = *stack;
	*stack = node;
}

/*
 * Shift up all elements of stack the by 1.
 * The first element becomes the last one.
 */
void	stack_rotate(t_stack **stack)
{
	t_stack	*it;
	t_stack	*first;

	if (*stack == NULL)
		return ;
	if ((*stack)->prev == NULL)
		return ;
	first = *stack;
	*stack = first->prev;
	first->prev = NULL;
	it = *stack;
	while (it->prev)
		it = it->prev;
	it->prev = first;
}

void	stack_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*next_last;

	if (*stack == NULL)
		return ;
	if ((*stack)->prev == NULL)
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

void	stack_push(t_stack **stack, int value)
{
	t_stack	*node;

	node = malloc(sizeof(*stack));
	node->value = value;
	node->prev = *stack;
	*stack = node;
}

int	stack_pop(t_stack **stack)
{
	t_stack	*node;
	int		res;

	node = *stack;
	res = node->value;
	*stack = node->prev;
	free(node);
	return (res);
}
