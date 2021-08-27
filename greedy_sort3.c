/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:14:38 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/27 18:59:32 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greedy_sort.h"
#include "stack_pair.h"

static void	insert_top_top(t_stack_pair *ss, t_params *params)
{
	int	k;
	int	m;

	m = ft_imin(params->p, params->q);
	k = 0;
	while (k++ < m)
		operation_rr(ss, true);
	k = 0;
	while (k++ < params->p - m)
		operation_ra(ss, true);
	k = 0;
	while (k++ < params->q - m)
		operation_rb(ss, true);
	params->pivot -= params->q;
}

static void	insert_bottom_bottom(t_stack_pair *ss, t_params *params)
{
	int	k;
	int	m;

	m = ft_imin(params->len_b - params->q, params->len_a - params->p);
	k = 0;
	while (k++ < m)
		operation_rrr(ss, true);
	k = 0;
	while (k++ < params->len_a - params->p - m)
		operation_rra(ss, true);
	k = 0;
	while (k++ < params->len_b - params->q - m)
		operation_rrb(ss, true);
	params->pivot += params->len_b - params->q;
}

static void	insert_top_bottom(t_stack_pair *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->p)
		operation_ra(ss, true);
	k = 0;
	while (k++ < params->len_b - params->q)
		operation_rrb(ss, true);
	params->pivot += params->len_b - params->q;
}

static void	insert_bottom_top(t_stack_pair *ss, t_params *params)
{
	int	k;

	k = 0;
	while (k++ < params->len_a - params->p)
		operation_rra(ss, true);
	k = 0;
	while (k++ < params->q)
		operation_rb(ss, true);
	params->pivot -= params->q;
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
