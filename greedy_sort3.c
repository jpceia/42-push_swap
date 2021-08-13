/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:14:38 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 05:17:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greedy_sort.h"
#include "double_stack.h"

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
	params->pivot -= (params->q +	 1);
}

void    apply_greedy_insertion(t_double_stack *ss, t_params *params)
{
	find_best_insertion(*ss, params);
	if (params->best_path == 0)
		insert_top_top(ss, params);
	else if (params->best_path == 1)
		insert_bottom_bottom(ss, params);
	else if (params->best_path == 2)
		insert_top_bottom(ss, params);
	else if (params->best_path == 3)
		insert_bottom_top(ss, params);
}
