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

void	double_stack_init(t_stack **a_ref, t_stack **b_ref)
{
	*a_ref = NULL;
	*b_ref = NULL;
}

void	double_stack_free(t_stack **a_ref, t_stack **b_ref)
{
	stack_free(a_ref);
	stack_free(b_ref);
}
