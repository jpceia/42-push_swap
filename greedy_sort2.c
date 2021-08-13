/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 04:59:07 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 08:20:27 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "double_stack.h"

static int	get_position(t_stack *stack, int val, int pivot)
{
	int	i;
	int	k;
	int	len;

	len = stack_len(stack);
	k = 0;
	while (k < len)
	{
		i = (pivot + k) % len;
		if (val > stack_at(stack, len - i - 1))
			return ((i - 1) % len);
		k++;
	}
	return ((pivot - 1) % len);
}

static void	set_nb_steps(int steps[4], t_params *params, int i, int j)
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

static void	find_best_insertion_step(
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

void	find_best_insertion(t_double_stack ss, t_params *params)
{
	int	i;

	i = params->len_b;
	params->min_steps = params->len_a + params->len_b + 1;
	while (ss.b)
	{
		i--;
		find_best_insertion_step(ss, params, i);
		ss.b = ss.b->prev;
	}
}
