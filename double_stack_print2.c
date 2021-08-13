/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_print2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:18:27 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 11:18:30 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_print_pa(t_double_stack *ss_ref)
{
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	operation_pa(ss_ref);
}

void	operation_print_pb(t_double_stack *ss_ref)
{
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	operation_pb(ss_ref);
}

void	operation_print_sa(t_double_stack *ss_ref)
{
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	operation_sa(ss_ref);
}

void	operation_print_sb(t_double_stack *ss_ref)
{
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	operation_sb(ss_ref);
}

void	operation_print_ss(t_double_stack *ss_ref)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	operation_ss(ss_ref);
}
