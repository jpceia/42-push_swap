/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:23:35 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/21 17:20:15 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

/*
 * Swaps the first two elements at the top of the stack
 * If the stack has no or only one elements (stack == NULL
 * or stack->prev == NULL) then do nothing
 */
t_stack	*stack_swap(t_stack **stack_ref)
{
	t_stack	*node;

	if (*stack_ref == NULL)
		return (NULL);
	node = (*stack_ref)->prev;
	if (node == NULL)
		return (*stack_ref);
	(*stack_ref)->prev = node->prev;
	node->prev = *stack_ref;
	*stack_ref = node;
	return (*stack_ref);
}

/*
 * Shift up all elements of stack the by 1.
 * The first element becomes the last one.
 */
t_stack	*stack_rotate(t_stack **stack_ref)
{
	t_stack	*it;
	t_stack	*first;

	if (*stack_ref == NULL)
		return (NULL);
	if ((*stack_ref)->prev == NULL)
		return (*stack_ref);
	first = *stack_ref;
	*stack_ref = first->prev;
	first->prev = NULL;
	it = *stack_ref;
	while (it->prev)
		it = it->prev;
	it->prev = first;
	return (*stack_ref);
}

t_stack	*stack_reverse_rotate(t_stack **stack_ref)
{
	t_stack	*last;
	t_stack	*next_last;

	if (*stack_ref == NULL)
		return (NULL);
	if ((*stack_ref)->prev == NULL)
		return (*stack_ref);
	last = *stack_ref;
	while (last->prev)
	{
		next_last = last;
		last = last->prev;
	}
	next_last->prev = NULL;
	last->prev = *stack_ref;
	*stack_ref = last;
	return (*stack_ref);
}

t_stack	*stack_push(t_stack **stack_ref, int value)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = *stack_ref;
	*stack_ref = node;
	return (*stack_ref);
}

int	stack_pop(t_stack **stack_ref)
{
	t_stack	*node;
	int		res;

	node = *stack_ref;
	res = node->value;
	*stack_ref = node->prev;
	free(node);
	return (res);
}
