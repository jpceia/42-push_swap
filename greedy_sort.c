/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/10 02:30:05 by jpceia           ###   ########.fr       */
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
	seq = NULL;
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

void	greedy_sort(t_stack *a)
{
	t_double_stack	ss;

	double_stack_init(&ss);
	ss.a = a;
	//double_stack_print(ss);
	greedy_sort_start(&ss);
	//greedy_sort_mid(&ss);
	//greedy_sort_finalize(&ss);
	double_stack_clear(&ss);
}

/*
static int	get_position(t_stack *stack, int val, int pivot)
{
	int	i;
	int	k;
	int	len;

	len = stack_len(stack);
	k = 0;
	while (k++ < len)
	{
		i = (pivot + k) % len;
		if (val > stack_at(stack, i))
			return ((i - 1) % len);
	}
	return ((pivot - 1) % len);
}

static void	select_best_path(int steps[4], int index[2], int args[2], int p[2])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (steps[k] < args[0])
		{
			args[0] = steps[k];
			args[1] = k;
			p[0] = index[0];
			p[1] = index[1];
		}
		k++;
	}
}

static int	best_insertion(t_double_stack ss, int pivot, int p[2])
{
	int	idx[2];
	int	len[2];
	int	args[2];
	int	steps[4];

	len[0] = stack_len(ss.a);
	len[1] = stack_len(ss.b);
	args[0] = len[0] + len[1] + 1;
	args[1] = 0;
	idx[0] = 0;
	while (idx[0] < len[0])
	{
		idx[1] = get_position(ss.a, ss.b->value, pivot);
		steps[0] = MAX(len[1] - idx[0], len[0] - idx[1]) - 1;
		steps[1] = MAX(idx[0], idx[1]) + 1;
		steps[2] = len[0] - idx[0] + idx[1];
		steps[3] = len[1] + idx[0] - idx[1];
		select_best_path(steps, idx, args, p);
		ss.b = ss.b->prev;
		idx[0]++;
	}
	return (args[1]);
}

static int	insert_top_top(t_double_stack *ss, int pivot, int p[2])
{
	int	k;
	int	len_a;
	int	len_b;

	len_a = stack_len(ss->a);
	len_b = stack_len(ss->b);
	k = 0;
	if (len_a - p[1] < len_b - p[0])
	{
		while (k++ < len_a - p[1] - 1)
			operation_rr(ss);
		k = 0;
		while (k++ < len_b - len_a - p[0] + p[1])
			operation_rb(ss);
	}
	else
	{
		while (k++ < len_b - p[0] - 1)
			operation_rr(ss);
		k = 0;
		while (k++ < len_a - len_b - p[1] + p[0])
			operation_ra(ss);
	}
	return (pivot + len_a - p[1] - 1);
}

static int	insert_bottom_bottom(t_double_stack *ss, int pivot, int p[2])
{
	int	k;

	k = 0;
	if (p[1] > p[0])
	{
		while (k++ < p[0] + 1)
			operation_rrr(ss);
		k = 0;
		while (k++ < p[1] - p[0])
			operation_rra(ss);
	}
	else
	{
		while (k++ < p[1] + 1)
			operation_rrr(ss);
		k = 0;
		while (k++ < p[0] - p[1])
			operation_rra(ss);
	}
	return (pivot - p[1] - 1);
}

static int	insert_bottom_top(t_double_stack *ss, int pivot, int p[2])
{
	int	k;
	int	len_a;

	len_a = stack_len(ss->a);
	k = 0;
	while (k++ < p[0] + 1)
		operation_rrb(ss);
	k = 0;
	while (k++ < p[1] + 1)
		operation_rra(ss);
	return (pivot + len_a - p[1] - 1);
}

static int	insert_top_bottom(t_double_stack *ss, int pivot, int p[2])
{
	int	k;
	int	len_b;

	len_b = stack_len(ss->b);
	k = 0;
	while (k++ < len_b - p[0] - 1)
		operation_rb(ss);
	k = 0;
	while (k++ < p[1] + 1)
		operation_rra(ss);
	return (pivot - p[1] - 1);
}

static int	apply_best_insertion(t_double_stack *ss, int path,
								int pivot, int p[2])
{
	if (path == 0)
		return (insert_top_top(ss, pivot, p));
	if (path == 1)
		return (insert_bottom_bottom(ss, pivot, p));
	if (path == 2)
		return (insert_top_bottom(ss, pivot, p));
	if (path == 3)
		return (insert_bottom_top(ss, pivot, p));
	return (-1);
}

static void	greedy_sort_insertion_step(t_double_stack *ss, int *pivot, int *pivot_val)
{
	int	p[2];
	int	len[2];
	int	path;
	int	new_val;

	len[0] = stack_len(ss->a);
	len[1] = stack_len(ss->b);
	path = best_insertion(*ss, *pivot, p);
	new_val = stack_at(ss->b, len[1] - p[0] - 1);
	*pivot = apply_best_insertion(ss, path, *pivot, p);
	if (new_val > *pivot_val)
	{
		*pivot = len[0];
		*pivot_val = new_val;
	}
	else
		*pivot %= len[0];
}

static void	greedy_sort_mid(t_double_stack *ss)
{
	int	k;
	int	len_a;
	int	len_b;
	int	pivot;
	int	pivot_val;

	len_a = stack_len(ss->a);
	len_b = stack_len(ss->b);
	pivot = len_a - 1 - stack_argmax(ss->a);
	pivot_val = stack_max(ss->a);
	k = 0;
	while (k++ < (int)len_b)
	{
		greedy_sort_insertion_step(ss, &pivot, &pivot_val);
		operation_pa(ss);
	}
}

static void	greedy_sort_finalize(t_double_stack *ss)
{
	int	len_a;
	int	pivot;

	len_a = stack_len(ss->a);
	pivot = len_a - stack_argmax(ss->a) - 1;
	if (pivot < len_a / 2)
	{
		while (pivot-- > 0)
			operation_rra(ss);
	}
	else
	{
		while (len_a > pivot++)
			operation_ra(ss);
	}
}

*/