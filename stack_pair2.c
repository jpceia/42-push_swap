/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:27:59 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 16:40:47 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"

/*
 * push a
 *
 * take the first element at the top of b and put it at the top of a. Do
 * nothing if b is empty.
 */
void	operation_pa(t_stack_pair *ss_ref, bool print)
{
	t_stack	*node;

	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_pb(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("pa");
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
void	operation_pb(t_stack_pair *ss_ref, bool print)
{
	t_stack	*node;

	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_pa(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("pb");
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
void	operation_sa(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_sb(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("sa");
	stack_swap(&ss_ref->a);
}

/*
 * swap b
 * 
 * swap the first 2 elements at the top of stack b. Do nothing if there
 * is only one or no elements).
 */
void	operation_sb(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_sa(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("sb");
	stack_swap(&ss_ref->b);
}

/*
 * swap a and b
 */
void	operation_ss(t_stack_pair *ss_ref, bool print)
{
	if (print)
		ft_putendl("ss");
	stack_swap(&ss_ref->a);
	stack_swap(&ss_ref->b);
}
