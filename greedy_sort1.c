/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 05:08:33 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "double_stack.h"

static void	greedy_sort_start(t_double_stack *ss)
{
	int	*arr;
	int	*seq;
	int	k;
	int	N;
	int	len_a;

	len_a = stack_len(ss->a);
	arr = stack_array(ss->a);
	N = longest_increasing_circular_subsequence(arr, len_a, &seq);
	free(arr);
	k = 0;
	while (k++ < len_a)
	{
		if (int_arr_contains(seq, N, stack_top(ss->a)))
			operation_ra(ss);
		else
		{
			operation_pb(ss);
			if (stack_top(ss->b) < len_a / 2)
				operation_rb(ss);
		}
	}
	free(seq);
}

static void	greedy_sort_insertion_step(t_double_stack *ss, t_params *params)
{
	apply_greedy_insertion(ss, params);
	if (params->new_val > params->pivot_val)
	{
		params->pivot = params->len_a;
		params->pivot_val = params->new_val;
	}
	else
	{
		params->pivot %= params->len_a;
		if (params->pivot < 0)
			params->pivot += params->len_a;
	}
}

static void	greedy_sort_core(t_double_stack *ss)
{
	t_params	params;

	params.len_a = stack_len(ss->a);
	params.len_b = stack_len(ss->b);
	params.pivot = params.len_a - stack_argmax(ss->a) - 1;
	params.pivot_val = stack_max(ss->a);
	while (ss->b)
	{
		greedy_sort_insertion_step(ss, &params);
		operation_pa(ss);
		params.len_a++;
		params.len_b--;
	}
}

static void	greedy_sort_finalize(t_double_stack *ss)
{
	int	len;
	int	pivot;

	len = stack_len(ss->a);
	pivot = len - stack_argmax(ss->a) - 1;
	if (pivot < len / 2)
	{
		while (pivot-- > 0)
			operation_rra(ss);
	}
	else
	{
		while (len > pivot++)
			operation_ra(ss);
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
