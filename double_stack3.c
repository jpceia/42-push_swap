/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:30:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/07 23:39:22 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_ra(t_stack **a, t_stack **b)
{
	(void)b;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	stack_rotate(a);
}

void	operation_rb(t_stack **a, t_stack **b)
{
	(void)a;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	stack_rotate(b);
}

void	operation_rr(t_stack **a, t_stack **b)
{
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	stack_rotate(a);
	stack_rotate(b);
}
