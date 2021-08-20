/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:14:38 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/20 23:34:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greedy_sort.h"
#include "stack_pair.h"

static void	insert_top_top(t_stack_pair *ss, t_params *params)
{
	int	k;
	int	m;

	m = ft_intmin(params->p, params->q);
	k = 0;
	while (k++ < m)
		operation_rr(ss, true);
	k = 0;
	while (k++ < params->p - m)
		operation_rb(ss, true);
	k = 0;
	while (k++ < params->q - m)
		operation_ra(ss, true);
	params->pivot -= params->q;
}

static void	insert_bottom_bottom(t_stack_pair *ss, t_params *params)
{
	int	k;
	int	m;

	m = ft_intmin(params->len_a - params->q, params->len_b - params->p);
	k = 0;
	while (k++ < m)
		operation_rrr(ss, true);
	k = 0;
	while (k++ < params->len_a - params->q - m)
		operation_rra(ss, true);
	k = 0;
	while (k++ < params->len_b - params->p - m)
		operation_rrb(ss, true);
	params->pivot += params->len_a - params->q;
}

static void	insert_bottom_top(t_stack_pair *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->len_b - params->p)
		operation_rrb(ss, true);
	k = 0;
	while (k++ < params->q)
		operation_ra(ss, true);
	params->pivot -= params->q;
}

static void	insert_top_bottom(t_stack_pair *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->p)
		operation_rb(ss, true);
	k = 0;
	while (k++ < params->len_a - params->q)
		operation_rra(ss, true);
	params->pivot += params->len_a - params->q;
}

void	apply_greedy_insertion(t_stack_pair *ss, t_params *params)
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
