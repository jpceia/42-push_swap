/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:16:55 by jpceia            #+#    #+#             */
/*   Updated: 2021/09/20 15:45:05 by jceia            ###   ########.fr       */
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
	int		n;

	(void)argc;
	stack_a = NULL;
	n = parse_args(argv + 1, &arr);
	if (n <= 0 && arr != NULL)
		free(arr);
	if (n == 0)
		return (EXIT_SUCCESS);
	if (arr == NULL || n < 0)
		push_swap_error();
	if (!arr_all_different(arr, n))
		push_swap_error();
	reverse(&arr, n);
	rankify(&arr, n);
	stack_push_array(&stack_a, arr, n);
	if (stack_is_sorted(stack_a))
		stack_clear(stack_a);
	else
		greedy_sort(stack_a);
	return (EXIT_SUCCESS);
}
