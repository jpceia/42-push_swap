/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:50:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 16:31:18 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PAIR_H
# define STACK_PAIR_H

# include "libft.h"
# include "stack.h"
# include <stdbool.h>

typedef struct s_stack_pair
{
	t_stack	*a;
	t_stack	*b;
	bool	reversed;
}	t_stack_pair;

void			stack_pair_print(t_stack_pair ss);
t_stack_pair	*stack_pair_init(t_stack_pair *ss_ref);
void			stack_pair_clear(t_stack_pair *ss_ref);
t_stack_pair	*stack_pair_reverse(t_stack_pair *ss_ref);

void			operation_pa(t_stack_pair *ss_ref, bool print);
void			operation_pb(t_stack_pair *ss_ref, bool print);
void			operation_sa(t_stack_pair *ss_ref, bool print);
void			operation_sb(t_stack_pair *ss_ref, bool print);
void			operation_ss(t_stack_pair *ss_ref, bool print);

void			operation_ra(t_stack_pair *ss_ref, bool print);
void			operation_rb(t_stack_pair *ss_ref, bool print);
void			operation_rr(t_stack_pair *ss_ref, bool print);

void			operation_rra(t_stack_pair *ss_ref, bool print);
void			operation_rrb(t_stack_pair *ss_ref, bool print);
void			operation_rrr(t_stack_pair *ss_ref, bool print);

#endif
