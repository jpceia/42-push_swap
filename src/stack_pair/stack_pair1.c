/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   stack_pair1.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jpceia <jpceia@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/07 23:16:33 by jpceia			#+#	#+#			 */
/*   Updated: 2021/08/07 23:16:35 by jpceia		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "stack_pair.h"

/**
 * @brief	Initializes a stack pair.
 * 
 * @param	ss_ref			reference to the stack pair.
 * @return	t_stack_pair*	pointer to the initialized stack pair.
 */
t_stack_pair	*stack_pair_init(t_stack_pair *ss_ref)
{
	ss_ref->a = NULL;
	ss_ref->b = NULL;
	ss_ref->reversed = false;
	return (ss_ref);
}

/**
 * @brief	Clears a stack pair.
 * 
 * @param	ss_ref		reference to the stack pair.
 */
void	stack_pair_clear(t_stack_pair *ss_ref)
{
	stack_clear(ss_ref->a);
	stack_clear(ss_ref->b);
}

/**
 * @brief   Reverses a stack pair (the left stack becomes the right stack and
 * 			vice versa).
 * 
 * @param	ss_ref			reference to the stack pair.
 * @return	t_stack_pair*	pointer to the reversed stack pair.
 */
t_stack_pair	*stack_pair_reverse(t_stack_pair *ss_ref)
{
	t_stack	*holder;

	holder = ss_ref->a;
	ss_ref->a = ss_ref->b;
	ss_ref->b = holder;
	ss_ref->reversed = !ss_ref->reversed;
	return (ss_ref);
}
