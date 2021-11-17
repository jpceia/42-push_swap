/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:22:13 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 22:43:47 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

/**
 * @brief	Prints a stack.
 * 
 * @param	stack
 */
void	stack_print(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->value);
		ft_putchar('\n');
		stack = stack->prev;
	}
	ft_putendl("____");
}

/**
 * @brief	Calculates the size of a given stack.
 * 
 * @param	stack 
 * @return	size_t	the size of the stack. 
 */
size_t	stack_len(t_stack *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->prev;
	}
	return (len);
}

/**
 * @brief	Gets the value of the top element of a stack.
 * 
 * @param	stack 
 * @return	int		value of the top element of the stack.
 */
int	stack_top(t_stack *stack)
{
	return (stack->value);
}

/**
 * @brief   Free the memory of a stack, including the memory of its nodes.
 * 
 * @param	stack 
 */
void	stack_clear(t_stack *stack)
{
	t_stack	*holder;

	if (!stack)
		return ;
	while (stack)
	{
		holder = stack->prev;
		free(stack);
		stack = holder;
	}
}

/**
 * @brief	Converts a stack to an array of integers.
 * 
 * @param	stack	the stack to convert.
 * @return	int*	the resulting array of integers. 
 */
int	*stack_array(t_stack *stack)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(*arr) * stack_len(stack));
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->prev;
	}
	return (arr);
}
