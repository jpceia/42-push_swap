/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 04:59:07 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/20 23:34:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack_pair.h"

static int	get_position(t_stack *stack, int val, int pivot)
{
	int	idx;
	int	k;
	int	len;

	len = stack_len(stack);
	k = 0;
	while (k < len)
	{
		idx = ft_mod(pivot + k, len);
		if (val < stack_at(stack, idx))
			return (ft_mod(idx, len));
		k++;
	}
	return (ft_mod(pivot, len));
}

static void	find_best_insertion_step(
	t_stack_pair ss, t_params *params, int i)
{
	int	j;
	int	k;
	int	steps[4];

	j = get_position(ss.a, ss.b->value, params->pivot);
	steps[0] = ft_intmax(i, j);
	steps[1] = ft_intmax(params->len_a - j, params->len_b - i);
	steps[2] = params->len_a - j + i;
	steps[3] = params->len_b - i + j;
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

void	find_best_insertion(t_stack_pair ss, t_params *params)
{
	int	i;

	i = 0;
	params->min_steps = params->len_a + params->len_b + 1;
	while (ss.b)
	{
		find_best_insertion_step(ss, params, i);
		ss.b = ss.b->prev;
		i++;
	}
}
