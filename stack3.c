/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:34:56 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 08:59:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int stack_at(t_stack *stack, size_t pos)
{
	while (pos--)
		stack = stack->prev;
	return (stack->value);
}

int	stack_argmax(t_stack *stack)
{
	int idx;
	int idx_max;
	int max;

	idx = 0;
	idx_max = 0;
	max = stack->value;
	stack = stack->prev;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			idx_max = idx;
		}
		idx++;
		stack = stack->prev;
	}
	return (idx_max);
}

int		stack_argmin(t_stack *stack)
{
	int idx;
	int idx_min;
	int min;

	idx = 0;
	idx_min = 0;
	min = stack->value;
	stack = stack->prev;
	while (stack)
	{
		if (stack->value > min)
		{
			min = stack->value;
			idx_min = idx;
		}
		idx++;
		stack = stack->prev;
	}
	return (idx_min);
}

int		stack_max(t_stack *stack)
{
	int max;

	max = stack->value;
	stack = stack->prev;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->prev;
	}
	return (max);
}

int		stack_min(t_stack *stack)
{
	int min;

	min = stack->value;
	stack = stack->prev;
	while (stack)
	{
		if (stack->value > min)
			min = stack->value;
		stack = stack->prev;
	}
	return (min);
}