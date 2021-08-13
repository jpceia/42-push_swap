/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 04:53:23 by jpceia           ###   ########.fr       */
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
		if (val > stack_at(stack, len - i - 1))
			return ((i - 1) % len);
	}
	return ((pivot - 1) % len);
}

static void set_nb_steps(int steps[4], t_params *params, int i, int j)
{
	if (params->len_a - j > params->len_b - i)
		steps[0] = params->len_a - j - 1;
	else
		steps[0] = params->len_b - i - 1;
	if (i > j)
		steps[1] = i + 1;
	else
		steps[1] = j + 1;
	steps[2] = params->len_b - i + j;
	steps[3] = params->len_a + i - j;
}

static void	best_insertion_step(
	t_double_stack ss, t_params *params, int i)
{
	int	j;
	int	k;
	int	steps[4];

	j = get_position(ss.a, ss.b->value, params->pivot);
	set_nb_steps(steps, params, i, j);
	k = 0;
	while (k < 4)
	{
		if (steps[k] < params->min_steps)
		{
			params->min_steps = steps[k];
			params->best_path = k;
			params->new_val = ss.b->value;
			params->p = i;
			params->q = j;
		}
		k++;
	}
}

static void	best_insertion(t_double_stack ss, t_params *params)
{
	int	i;

	i = params->len_b;
	params->min_steps = params->len_a + params->len_b + 1;
	while (ss.b)
	{
		i--;
		best_insertion_step(ss, params, i);
		ss.b = ss.b->prev;
	}
}

static void	insert_top_top(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	if (params->len_a - params->q < params->len_b - params->p)
	{
		while (k++ < params->len_a - params->q - 1)
			operation_rr(ss);
		k = 0;
		while (k++ < params->len_b - params->len_a - params->p + params->q)
			operation_rb(ss);
	}
	else
	{
		while (k++ < params->len_b - params->p - 1)
			operation_rr(ss);
		k = 0;
		while (k++ < params->len_a - params->len_b - params->q + params->p)
			operation_ra(ss);
	}
	params->pivot += params->len_a - params->q - 1;
}

static void	insert_bottom_bottom(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	if (params->q > params->p)
	{
		while (k++ <  params->p + 1)
			operation_rrr(ss);
		k = 0;
		while (k++ < params->q - params->p)
			operation_rra(ss);
	}
	else
	{
		while (k++ < params->q + 1)
			operation_rrr(ss);
		k = 0;
		while (k++ < params->p - params->q)
			operation_rrb(ss);
	}
	params->pivot -= (params->q + 1);
}

static void	insert_bottom_top(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->p + 1)
		operation_rrb(ss);
	k = 0;
	while (k++ < params->len_a - params->q - 1)
		operation_ra(ss);
	params->pivot += params->len_a - params->q - 1;
}

static void	insert_top_bottom(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->len_b - params->p - 1)
		operation_rb(ss);
	k = 0;
	while (k++ < params->q + 1)
		operation_rra(ss);
	params->pivot -= (params->q + 1);
}

static void apply_best_insertion(t_double_stack *ss, t_params *params)
{
	best_insertion(*ss, params);
	if (params->best_path == 0)
		insert_top_top(ss, params);
	else if (params->best_path == 1)
		insert_bottom_bottom(ss, params);
	else if (params->best_path == 2)
		insert_top_bottom(ss, params);
	else if (params->best_path == 3)
		insert_bottom_top(ss, params);
}

static void	greedy_sort_insertion_step(t_double_stack *ss, t_params *params)
{
	apply_best_insertion(ss, params);
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

void	greedy_sort_mid(t_double_stack *ss)
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
	int len;
	int pivot;

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
	greedy_sort_mid(&ss);
	greedy_sort_finalize(&ss);
	double_stack_clear(&ss);
}
