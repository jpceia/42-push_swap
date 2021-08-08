/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:20:04 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 03:39:44 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef	struct	s_stack
{
	int				value;
	struct s_stack	*prev;
}	t_stack;

void	stack_print(t_stack *stack);
size_t	stack_len(t_stack *stack);
int		stack_top(t_stack *stack);
void	stack_free(t_stack **stack_ref);

void	stack_swap(t_stack **stack_ref);
void	stack_rotate(t_stack **stack_ref);
void	stack_reverse_rotate(t_stack **stack_ref);
t_stack	*stack_push(t_stack **stack_ref, int value);
int		stack_pop(t_stack **stack_ref);

#endif