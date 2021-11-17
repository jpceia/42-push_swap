/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:24:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 22:46:24 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

/**
 * @brief	Checks if a given stack is sorted by ascending order.
 * 
 * @param	stack
 * @return	int		1 if sorted, 0 otherwise
 */
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

/**
 * @brief Adds N new elements to the stack
 * 
 * @param stack_ref	reference to the stack to be modified.
 * @param arr		the array of values to add, with N elements.
 * @param N			the number of values to add.
 * @return t_stack*	the modified stack.
 */
t_stack	*stack_push_array(t_stack **stack_ref, int *arr, size_t N)
{
	size_t	idx;

	idx = 0;
	while (idx < N)
	{
		stack_push(stack_ref, arr[idx]);
		idx++;
	}
	free(arr);
	return (*stack_ref);
}

/**
 * @brief	Creates a copy of a given stack.
 * 
 * @param	stack		the stack to be copied.
 * @return	t_stack*	the resulting copy.
 */
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
