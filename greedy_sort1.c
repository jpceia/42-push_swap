/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/20 22:19:07 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "double_stack.h"

static void	greedy_sort_start(t_double_stack *ss)
{
	int	*seq;
	int	N;
	int	seq_size;
	int	len_a;

	N = stack_len(ss->a);
	len_a = N;
	seq_size = LICS_stack(ss->a, &seq);
	while (seq_size < len_a)
	{
		if (int_arr_contains(seq, seq_size, stack_top(ss->a)))
			operation_ra(ss, true);
		else
		{
			operation_pb(ss, true);
			if ((N > 20) && (stack_top(ss->b) < N / 2))
				operation_rb(ss, true);
			len_a--;
		}
	}
	free(seq);
}

static void	greedy_sort_insertion_step(t_double_stack *ss, t_params *params)
{
	apply_greedy_insertion(ss, params);
	if (params->new_val < params->pivot_val)
	{
		params->pivot = 0;
		params->pivot_val = params->new_val;
	}
	else
		params->pivot = ft_mod(params->pivot, params->len_a) + 1;
}

static void	greedy_sort_core(t_double_stack *ss)
{
	t_params	params;

	params.len_a = stack_len(ss->a);
	params.len_b = stack_len(ss->b);
	params.pivot = stack_argmin(ss->a);
	params.pivot_val = stack_min(ss->a);
	while (ss->b)
	{
		greedy_sort_insertion_step(ss, &params);
		operation_pa(ss, true);
		params.len_a++;
		params.len_b--;
	}
}

static void	greedy_sort_finalize(t_double_stack *ss)
{
	int	len;
	int	pivot;

	len = stack_len(ss->a);
	pivot = stack_argmin(ss->a);
	if (pivot < len / 2)
	{
		while (pivot-- > 0)
			operation_ra(ss, true);
	}
	else
	{
		while (pivot++ < len)
			operation_rra(ss, true);
	}
}

void	greedy_sort(t_stack *a)
{
	t_double_stack	ss;

	double_stack_init(&ss);
	ss.a = a;
	greedy_sort_start(&ss);
	greedy_sort_core(&ss);
	greedy_sort_finalize(&ss);
	double_stack_clear(&ss);
}
