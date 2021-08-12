/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:35:50 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/12 16:02:17 by jceia            ###   ########.fr       */
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

static void	best_insertion(t_double_stack ss, t_params *params)
{
	int i;
	int j;
	int path;
	int min_steps;
	int	steps[4];

	i = 0;
	min_steps = params->len_a + params->len_b + 1;
	while (i < params->len_a)
	{
		j = get_position(ss.a, ss.b->value, params->pivot);
		steps[0] = params->len_a - j > params->len_b - i ?
			params->len_a - j - 1 : params->len_b - i - 1;
		steps[1] = (i > j ? i : j) + 1;
		steps[2] = params->len_b - i + j;
		steps[3] = params->len_a + i - j;
		path = 0;
		while (path < 4)
		{
			if (steps[path] < params->min_steps)
			{
				min_steps = steps[path];
				params->best_path = path;
				params->p = i;
				params->q = j;
			}
			path++;
		}
		ss.b = ss.b->prev;
		i++;
	}
}



static int	insert_top_top(t_double_stack *ss, t_params *params)
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
	return (params->pivot + params->len_a - params->q - 1);
}

static int	insert_bottom_bottom(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	if (params->q > params->p)
	{
		while (k++ < params->p + 1)
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
			operation_rra(ss);
	}
	return (params->pivot - params->q - 1);
}

static int	insert_bottom_top(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->p + 1)
		operation_rrb(ss);
	k = 0;
	while (k++ < params->q + 1)
		operation_rra(ss);
	return (params->pivot + params->len_a - params->q - 1);
}

static int	insert_top_bottom(t_double_stack *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->len_b - params->p - 1)
		operation_rb(ss);
	k = 0;
	while (k++ < params->q + 1)
		operation_rra(ss);
	return (params->pivot - params->q - 1);
}


static int	apply_best_insertion(t_double_stack *ss, t_params *params)
{
	if (params->best_path == 0)
		return (insert_top_top(ss, params));
	if (params->best_path == 1)
		return (insert_bottom_bottom(ss, params));
	if (params->best_path == 2)
		return (insert_top_bottom(ss, params));
	if (params->best_path == 3)
		return (insert_bottom_top(ss, params));
	return (-1);
}

static void	greedy_sort_insertion_step(t_double_stack *ss, t_params *params)
{
	int	new_val;

	best_insertion(*ss, params);
	new_val = stack_at(ss->b, params->len_b - params->p - 1);
	params->pivot = apply_best_insertion(ss, params);
	if (new_val > params->pivot_val)
	{
		params->pivot = params->len_a;
		params->pivot_val = new_val;
	}
	else
		params->pivot %= params->len_a;
}



void	greedy_sort_mid(t_double_stack *ss)
{
	t_params	params;

	params.len_a = stack_len(ss->a);
	params.len_b = stack_len(ss->b);
	params.pivot = params.len_a - 1 - stack_argmax(ss->a);
	params.pivot_val = stack_max(ss->a);
	while (params.len_b > 0)
	{
		greedy_sort_insertion_step(ss, &params);
		operation_pa(ss);
		params.len_a++;
		params.len_b--;
	}
}



/*
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


void	greedy_sort(t_stack *a)
{
	t_double_stack	ss;

	double_stack_init(&ss);
	ss.a = a;
	//double_stack_print(ss);
	greedy_sort_start(&ss);
	greedy_sort_mid(&ss);
	//greedy_sort_finalize(&ss);
	double_stack_clear(&ss);
}
