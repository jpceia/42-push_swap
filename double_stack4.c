/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:38:58 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/07 23:39:18 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_rra(t_stack **a, t_stack **b)
{
	(void)b;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	stack_reverse_rotate(a);
}

void	operation_rrb(t_stack **a, t_stack **b)
{
	(void)a;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	stack_reverse_rotate(b);
}

void	operation_rrr(t_stack **a, t_stack **b)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}
