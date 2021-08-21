/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:38:58 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 16:32:45 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"

void	operation_rra(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_rrb(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->a);
}

void	operation_rrb(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_rra(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->b);
}

void	operation_rrr(t_stack_pair *ss_ref, bool print)
{
	if (print)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->a);
	stack_reverse_rotate(&ss_ref->b);
}
