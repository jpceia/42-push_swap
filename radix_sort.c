/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:56 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/20 23:34:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_pair.h"

void	small_sort(t_stack *a)
{
	t_stack_pair	ss;

	stack_pair_init(&ss);
	ss.a = a;
	stack_pair_print(ss);
	stack_pair_clear(&ss);
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
	t_stack_pair	ss;

	stack_pair_init(&ss);
	ss.a = a;
	N = stack_len(a);
	shift = 0;
	while (shift < bit_length(N))
	{
		k = 0;
		while (k++ < N)
		{
			if ((stack_top(ss.a) >> shift) & 1)
				operation_ra(&ss, true);
			else
				operation_pb(&ss, true);
		}
		while (ss.b)
			operation_pa(&ss, true);
		shift++;
	}
	stack_pair_clear(&ss);
}
