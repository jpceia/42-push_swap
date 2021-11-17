/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:34:56 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 22:46:15 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief	Gets the value of an element of a stack by index.
 * @note	It can segfault if the index is out of bounds.
 * 
 * @param	stack	the stack to be searched.
 * @param	pos		the index of the element.
 * @return	int		the value of the element.
 */
int	stack_at(t_stack *stack, size_t pos)
{
	while (pos--)
		stack = stack->prev;
	return (stack->value);
}

/**
 * @brief	Gets the index of the element in the stack with the highest value.
 * 
 * @param	stack
 * @return	int		the index of the element with the highest value.
 */
int	stack_argmax(t_stack *stack)
{
	int	idx;
	int	idx_max;
	int	max;

	idx = 0;
	idx_max = 0;
	max = stack->value;
	stack = stack->prev;
	while (stack)
	{
		idx++;
		if (stack->value > max)
		{
			max = stack->value;
			idx_max = idx;
		}
		stack = stack->prev;
	}
	return (idx_max);
}

/**
 * @brief	Gets the index of the element in the stack with the lowest value.
 * 
 * @param	stack
 * @return	int		the index of the element with the lowest value.
 */
int	stack_argmin(t_stack *stack)
{
	int	idx;
	int	idx_min;
	int	min;

	idx = 0;
	idx_min = 0;
	min = stack->value;
	stack = stack->prev;
	while (stack)
	{
		idx++;
		if (stack->value < min)
		{
			min = stack->value;
			idx_min = idx;
		}
		stack = stack->prev;
	}
	return (idx_min);
}

/**
 * @brief	Gets the highest value in the stack.
 * 
 * @param	stack
 * @return	int		the highest value in the stack.
 */
int	stack_max(t_stack *stack)
{
	int	max;

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

/**
 * @brief	Gets the lowest value in the stack.
 * 
 * @param	stack 
 * @return	int		the lowest value in the stack.
 */
int	stack_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	stack = stack->prev;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->prev;
	}
	return (min);
}
