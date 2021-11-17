/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:22:13 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/27 19:27:17 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

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

int	stack_top(t_stack *stack)
{
	return (stack->value);
}

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
