/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:20:04 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/07 23:51:24 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK
# define STACK

# include <stddef.h>

typedef	struct	s_stack
{
	int				value;
	struct s_stack	*prev;
}	t_stack;

void	stack_print(t_stack *stack);
size_t	stack_len(t_stack *stack);
int		stack_top(t_stack *stack);
void	stack_free(t_stack **stack);

void	stack_swap(t_stack **stack);
void	stack_rotate(t_stack **stack);
void	stack_reverse_rotate(t_stack **stack);
void	stack_push(t_stack **stack, int data);
int		stack_pop(t_stack **stack);

#endif