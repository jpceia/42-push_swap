/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:15:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 21:55:13 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREEDY_SORT_H
# define GREEDY_SORT_H

# include "stack.h"
# include "stack_pair.h"

typedef struct s_params {
	int	len_a;
	int	len_b;
	int	pivot;
	int	pivot_val;
	int	min_steps;
	int	best_path;
	int	new_val;
	int	p;
	int	q;
}	t_params;

void	greedy_sort(t_stack *stack);
void	apply_greedy_insertion(t_stack_pair *ss, t_params *params);
void	greedy_sort_insertion_step(t_stack_pair *ss, t_params *params);
void	find_best_insertion(t_stack_pair ss, t_params *params);

#endif
