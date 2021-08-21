/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:24:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/21 17:14:19 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

int	stack_is_sorted(t_stack *stack)
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

t_stack	*stack_push_array(t_stack **stack, int *arr, size_t N)
{
	size_t	idx;

	idx = 0;
	while (idx < N)
	{
		stack_push(stack, arr[idx]);
		idx++;
	}
	free(arr);
	return (*stack);
}

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;

	if (stack == NULL)
		return (NULL);
	copy = malloc(sizeof(*copy));
	if (!copy)
		return (NULL);
	copy->value = stack->value;
	copy->prev = stack_copy(stack->prev);
	return (copy);
}
