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

t_stack_pair	*stack_pair_init(t_stack_pair *ss_ref)
{
	ss_ref->a = NULL;
	ss_ref->b = NULL;
	return (ss_ref);
}

void	stack_pair_clear(t_stack_pair *ss_ref)
{
	stack_clear(ss_ref->a);
	stack_clear(ss_ref->b);
}
