/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:16:55 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/21 07:16:11 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_pair.h"
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		N;

	(void)argc;
	stack_a = NULL;
	N = parse_args(argv + 1, &arr);
	if (N == 0 && arr != NULL)
		free(arr);
	if (N == 0 || arr == NULL)
		push_swap_error();
	if (!arr_all_different(arr, N))
		push_swap_error();
	reverse(&arr, N);
	rankify(&arr, N);
	if (!stack_push_array(&stack_a, arr, N))
		push_swap_error();
	if (stack_is_sorted(stack_a))
		stack_clear(stack_a);
	else
		greedy_sort(stack_a);
	return (0);
}
