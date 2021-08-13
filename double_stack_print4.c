/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_print4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:18:45 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 10:53:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_print_rra(t_double_stack *ss_ref)
{
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	operation_rra(ss_ref);
}

void	operation_print_rrb(t_double_stack *ss_ref)
{
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	operation_rrb(ss_ref);
}

void	operation_print_rrr(t_double_stack *ss_ref)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	operation_rrr(ss_ref);
}
