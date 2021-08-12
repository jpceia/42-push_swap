/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:16:55 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/09 14:19:56 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "double_stack.h"
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int *arr;
	int N;

	N = argc - 1;
	stack_a = NULL;
	arr = parse_args(argv + 1, N);
	if (arr == NULL)
		push_swap_exit();
	if (!arr_all_different(arr, N))
		push_swap_exit();
	reverse(&arr, N);
	rankify(&arr, N);
	if (!stack_push_array(&stack_a, arr, N))
		push_swap_exit();
	if (stack_is_sorted(stack_a))
	{
		stack_clear(stack_a);
		return (0);
	}
	greedy_sort(stack_a);
	return (0);
}