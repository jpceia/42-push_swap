/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:50:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 03:39:53 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_STACK_H
# define DOUBLE_STACK_H

# include "libft.h"
# include "stack.h"

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

void	double_stack_print(t_stack *a, t_stack *b);
void	double_stack_init(t_stack **a_ref, t_stack **b_ref);
void	double_stack_free(t_stack **a_ref, t_stack **b_ref);

void	operation_pa(t_stack **a_ref, t_stack **b_ref);
void	operation_pb(t_stack **a_ref, t_stack **b_ref);
void	operation_sa(t_stack **a_ref, t_stack **b_ref);
void	operation_sb(t_stack **a_ref, t_stack **b_ref);
void	operation_ss(t_stack **a_ref, t_stack **b_ref);

void	operation_ra(t_stack **a_ref, t_stack **b_ref);
void	operation_rb(t_stack **a_ref, t_stack **b_ref);
void	operation_rr(t_stack **a_ref, t_stack **b_ref);

void	operation_rra(t_stack **a_ref, t_stack **b_ref);
void	operation_rrb(t_stack **a_ref, t_stack **b_ref);
void	operation_rrr(t_stack **a_ref, t_stack **b_ref);

#endif