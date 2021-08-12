/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:16:55 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/12 16:08:24 by jceia            ###   ########.fr       */
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

	(void)argc;
	stack_a = NULL;
	N = parse_args(argv + 1, &arr);
	if (arr == NULL)
		push_swap_error();
	if (!arr_all_different(arr, N))
		push_swap_error();
	reverse(&arr, N);
	rankify(&arr, N);
	if (!stack_push_array(&stack_a, arr, N))
		push_swap_error();
	if (stack_is_sorted(stack_a))
	{
		stack_clear(stack_a);
		return (0);
	}
	//radix_sort(stack_a);
	greedy_sort(stack_a);
	return (0);
}
