/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/09/20 15:45:17 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_pair.h"

static int	try_swap(t_stack_pair *ss, int *seq_size, int **seq)
{
	t_stack	*a;
	int		*trial_seq;
	int		trial_seq_size;
	int		swap_b;

	a = stack_copy(ss->a);
	trial_seq_size = lics_stack(stack_swap(&a), &trial_seq);
	stack_clear(a);
	if (trial_seq_size <= *seq_size)
	{
		free(trial_seq);
		return (0);
	}
	free(*seq);
	*seq = trial_seq;
	*seq_size = trial_seq_size;
	swap_b = 0;
	if (ss->b && ss->b->prev)
		if (ss->b->prev->value > ss->b->value)
			swap_b = 1;
	if (swap_b)
		operation_ss(ss, true);
	else
		operation_sa(ss, true);
	return (1);
}

static void	push_all_except_lics(t_stack_pair *ss)
{
	int	*seq;
	int	n;
	int	seq_size;
	int	len_a;

	n = stack_len(ss->a);
	len_a = n;
	seq_size = lics_stack(ss->a, &seq);
	try_swap(ss, &seq_size, &seq);
	while (seq_size < len_a)
	{
		if (int_arr_contains(seq, seq_size, stack_top(ss->a)))
			operation_ra(ss, true);
		else
		{
			operation_pb(ss, true);
			if ((n > 20) && (stack_top(ss->b) < n / 2))
				operation_rb(ss, true);
			len_a--;
		}
		if (n <= 20)
			try_swap(ss, &seq_size, &seq);
	}
	free(seq);
}

static void	greedy_sort_core(t_stack_pair *ss)
{
	t_params	params;

	params.len_a = stack_len(ss->a);
	params.len_b = stack_len(ss->b);
	params.pivot = stack_argmin(ss->b);
	params.pivot_val = stack_min(ss->b);
	while (ss->a)
	{
		greedy_sort_insertion_step(ss, &params);
		operation_pb(ss, true);
		params.len_b++;
		params.len_a--;
	}
}

static void	adjust_pivot(t_stack_pair *ss)
{
	int	len;
	int	pivot;

	len = stack_len(ss->a);
	pivot = stack_argmin(ss->a);
	if (pivot <= len / 2)
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
	t_stack_pair	ss;

	stack_pair_init(&ss);
	ss.a = a;
	push_all_except_lics(&ss);
	stack_pair_reverse(&ss);
	greedy_sort_core(&ss);
	stack_pair_reverse(&ss);
	adjust_pivot(&ss);
	stack_pair_clear(&ss);
}
