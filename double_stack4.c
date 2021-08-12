/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:38:58 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 12:09:34 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	operation_rra(t_double_stack *ss_ref)
{
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->a);
}

void	operation_rrb(t_double_stack *ss_ref)
{
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->b);
}

void	operation_rrr(t_double_stack *ss_ref)
{
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	stack_reverse_rotate(&ss_ref->a);
	stack_reverse_rotate(&ss_ref->b);
}
