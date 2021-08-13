/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_print3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:18:29 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 10:52:48 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_print_ra(t_double_stack *ss_ref)
{
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	operation_ra(ss_ref);
}

void	operation_print_rb(t_double_stack *ss_ref)
{
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	operation_rb(ss_ref);
}

void	operation_print_rr(t_double_stack *ss_ref)
{
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	operation_rr(ss_ref);
}
