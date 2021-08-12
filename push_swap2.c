/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:02:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/09 14:22:06 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int *reverse(int **arr_ref, size_t N)
{
	int k;
	int holder;

	k = 0;
	while (k < (int)(N / 2))
	{
		holder = (*arr_ref)[k];
		(*arr_ref)[k] = (*arr_ref)[N - k - 1];
		(*arr_ref)[N - k - 1] = holder;
		k++;
	}
	return (*arr_ref);
}

int	arr_all_different(int *arr, size_t N)
{
	int i;
	int j;

	i = 0;
	while (i < (int)(N-1))
	{
		j = i + 1;
		while (j < (int)N)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

/*
 *check what happens if stack_push fails
 */
t_stack *stack_push_array(t_stack **stack, int *arr, size_t N)
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
