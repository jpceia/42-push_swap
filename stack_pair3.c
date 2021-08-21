/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:30:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 16:32:34 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"

void	operation_ra(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_rb(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->a);
}

void	operation_rb(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_ra(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->b);
}

void	operation_rr(t_stack_pair *ss_ref, bool print)
{
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->a);
	stack_rotate(&ss_ref->b);
}
