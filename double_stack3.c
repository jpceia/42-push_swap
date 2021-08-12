/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:30:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/09 19:34:14 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_ra(t_double_stack *ss_ref)
{
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->a);
}

void	operation_rb(t_double_stack *ss_ref)
{
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->b);
}

void	operation_rr(t_double_stack *ss_ref)
{
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	stack_rotate(&ss_ref->a);
	stack_rotate(&ss_ref->b);
}
