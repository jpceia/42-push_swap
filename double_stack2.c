/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:27:59 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 00:42:47 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

/*
 * push a
 *
 * take the first element at the top of b and put it at the top of a. Do
 * nothing if b is empty.
 */
void	operation_pa(t_stack **a_ref, t_stack **b_ref)
{
	t_stack	*node;

	ft_putstr_fd("pa\n", STDOUT_FILENO);
	node = *b_ref;
	if (node == NULL)
		return ;
	*b_ref = node->prev;
	node->prev = *a_ref;
	*a_ref = node;
}

/*
 * push b
 *
 * take the first element at the top of a and put it at the top of b. Do
 * nothing if a is empty.
 */
void	operation_pb(t_stack **a_ref, t_stack **b_ref)
{
	t_stack	*node;

	ft_putstr_fd("pb\n", STDOUT_FILENO);
	node = *a_ref;
	if (node == NULL)
		return ;
	*a_ref = node->prev;
	node->prev = *b_ref;
	*b_ref = node;
}

/*
 * swap a
 * 
 * swap the first 2 elements at the top of stack a. Do nothing if there
 * is only one or no elements).
 */
void	operation_sa(t_stack **a_ref, t_stack **b_ref)
{
	(void)b_ref;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	stack_swap(a_ref);
}

void	operation_sb(t_stack **a_ref, t_stack **b_ref)
{
	(void)a_ref;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	stack_swap(b_ref);
}

void	operation_ss(t_stack **a_ref, t_stack **b_ref)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	stack_swap(a_ref);
	stack_swap(b_ref);
}
