/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:56 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 10:17:40 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "double_stack.h"

void	small_sort(t_stack *a)
{
	t_double_stack	ss;

	double_stack_init(&ss);
	ss.a = a;
	double_stack_print(ss);
	double_stack_clear(&ss);
}

size_t	bit_length(unsigned int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

void	radix_sort(t_stack *a)
{
	size_t			k;
	size_t			N;
	size_t			shift;
	t_double_stack	ss;

	double_stack_init(&ss);
	ss.a = a;
	N = stack_len(a);
	shift = 0;
	while (shift < bit_length(N))
	{
		k = 0;
		while (k++ < N)
		{
			if ((stack_top(ss.a) >> shift) & 1)
				operation_print_ra(&ss);
			else
				operation_print_pb(&ss);
		}
		while (ss.b)
			operation_print_pa(&ss);
		shift++;
	}
	double_stack_clear(&ss);
}
