/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   double_stack1.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jpceia <jpceia@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/07 23:16:33 by jpceia			#+#	#+#			 */
/*   Updated: 2021/08/07 23:16:35 by jpceia		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "double_stack.h"

t_double_stack	*double_stack_init(t_double_stack *ss_ref)
{
	ss_ref->a = NULL;
	ss_ref->b = NULL;
	return (ss_ref);
}

void	double_stack_clear(t_double_stack *ss_ref)
{
	stack_clear(ss_ref->a);
	stack_clear(ss_ref->b);
}
