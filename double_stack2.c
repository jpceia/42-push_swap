/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:27:59 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/07 23:29:50 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

/*
 * push a
 *
 * take the first element at the top of b and put it at the top of a. Do
 * nothing if b is empty.
 */
void	operation_pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	ft_putstr_fd("pa\n", STDOUT_FILENO);
	node = *b;
	if (node == NULL)
		return ;
	*b = node->prev;
	node->prev = *a;
	*a = node;
}

/*
 * push b
 *
 * take the first element at the top of a and put it at the top of b. Do
 * nothing if a is empty.
 */
void	operation_pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	ft_putstr_fd("pb\n", STDOUT_FILENO);
	node = *a;
	if (node == NULL)
		return ;
	*a = node->prev;
	node->prev = *b;
	*b = node;
}

/*
 * swap a
 * 
 * swap the first 2 elements at the top of stack a. Do nothing if there
 * is only one or no elements).
 */
void	operation_sa(t_stack **a, t_stack **b)
{
	(void)b;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	stack_swap(a);
}

void	operation_sb(t_stack **a, t_stack **b)
{
	(void)a;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	stack_swap(b);
}

void	operation_ss(t_stack **a, t_stack **b)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	stack_swap(a);
	stack_swap(b);
}
