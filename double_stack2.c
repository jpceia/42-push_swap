/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:27:59 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/09 19:35:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

/*
 * push a
 *
 * take the first element at the top of b and put it at the top of a. Do
 * nothing if b is empty.
 */
void	operation_pa(t_double_stack *ss_ref)
{
	t_stack	*node;

	ft_putstr_fd("pa\n", STDOUT_FILENO);
	node = ss_ref->b;
	if (node == NULL)
		return ;
	ss_ref->b = node->prev;
	node->prev = ss_ref->a;
	ss_ref->a = node;
}

/*
 * push b
 *
 * take the first element at the top of a and put it at the top of b. Do
 * nothing if a is empty.
 */
void	operation_pb(t_double_stack *ss_ref)
{
	t_stack	*node;

	ft_putstr_fd("pb\n", STDOUT_FILENO);
	node = ss_ref->a;
	if (node == NULL)
		return ;
	ss_ref->a = node->prev;
	node->prev = ss_ref->b;
	ss_ref->b = node;
}

/*
 * swap a
 * 
 * swap the first 2 elements at the top of stack a. Do nothing if there
 * is only one or no elements).
 */
void	operation_sa(t_double_stack *ss_ref)
{
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	stack_swap(&ss_ref->a);
}

/*
 * swap b
 * 
 * swap the first 2 elements at the top of stack b. Do nothing if there
 * is only one or no elements).
 */
void	operation_sb(t_double_stack *ss_ref)
{
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	stack_swap(&ss_ref->b);
}

/*
 * swap a and b
 */
void	operation_ss(t_double_stack *ss_ref)
{
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	stack_swap(&ss_ref->a);
	stack_swap(&ss_ref->b);
}
