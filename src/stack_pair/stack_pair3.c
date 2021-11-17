/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:30:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 16:32:34 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"

/**
 * @brief	rotate a
 * 			Shifts up all elements of stack a by one position.
 * 			The first element becomes the last one.
 * 
 * @param	ss_ref	reference to the stack pair.
 * @param	print	if true, print the operation.
 */
void	operation_ra(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_rb(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("ra");
	stack_rotate(&ss_ref->a);
}

/**
 * @brief	rotate b
 * 			Shifts up all elements of stack b by one position.
 * 			The first element becomes the last one.
 * 
 * @param	ss_ref	reference to the stack pair.
 * @param	print	if true, print the operation. 
 */
void	operation_rb(t_stack_pair *ss_ref, bool print)
{
	if (ss_ref->reversed)
	{
		stack_pair_reverse(ss_ref);
		operation_ra(ss_ref, print);
		stack_pair_reverse(ss_ref);
		return ;
	}
	if (print)
		ft_putendl("rb");
	stack_rotate(&ss_ref->b);
}

/**
 * @brief	rotate a and b
 * 			Applies the operations ra and rb.
 * 
 * @param	ss_ref	reference to the stack pair.
 * @param	print	if true, print the operation.
 */
void	operation_rr(t_stack_pair *ss_ref, bool print)
{
	if (print)
		ft_putendl("rr");
	stack_rotate(&ss_ref->a);
	stack_rotate(&ss_ref->b);
}
