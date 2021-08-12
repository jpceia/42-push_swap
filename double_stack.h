/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:50:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/09 19:31:43 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_STACK_H
# define DOUBLE_STACK_H

# include "libft.h"
# include "stack.h"

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct	s_double_stack
{
	t_stack	*a;
	t_stack	*b;
}				t_double_stack;

void	double_stack_print(t_double_stack ss);
t_double_stack	*double_stack_init(t_double_stack *ss_ref);
void	double_stack_clear(t_double_stack *ss_ref);

void	operation_pa(t_double_stack *ss_ref);
void	operation_pb(t_double_stack *ss_ref);
void	operation_sa(t_double_stack *ss_ref);
void	operation_sb(t_double_stack *ss_ref);
void	operation_ss(t_double_stack *ss_ref);

void	operation_ra(t_double_stack *ss_ref);
void	operation_rb(t_double_stack *ss_ref);
void	operation_rr(t_double_stack *ss_ref);

void	operation_rra(t_double_stack *ss_ref);
void	operation_rrb(t_double_stack *ss_ref);
void	operation_rrr(t_double_stack *ss_ref);

#endif