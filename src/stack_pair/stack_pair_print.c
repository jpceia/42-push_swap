/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_print1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:23:29 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 10:57:32 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"

static void	stack_pair_print_line(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	ft_putstr(s1);
	while (6 > len++)
	{
		ft_putchar(' ');
	}
	ft_putstr(s2);
	ft_putchar('\n');
}

static void	stack_pair_print_both(t_stack_pair ss, int N)
{
	char	*s1;
	char	*s2;

	while (N--)
	{
		s1 = ft_itoa(ss.a->value);
		s2 = ft_itoa(ss.b->value);
		stack_pair_print_line(s1, s2);
		free(s1);
		free(s2);
		ss.a = ss.a->prev;
		ss.b = ss.b->prev;
	}
}

static void	stack_pair_print_left(t_stack *stack, int N)
{
	char	*s;

	while (N-- > 0)
	{
		s = ft_itoa(stack->value);
		stack_pair_print_line(s, "");
		free(s);
		stack = stack->prev;
	}
}

static void	stack_pair_print_right(t_stack *stack, int N)
{
	char	*s;

	while (N-- > 0)
	{
		s = ft_itoa(stack->value);
		stack_pair_print_line("", s);
		free(s);
		stack = stack->prev;
	}
}

/**
 * @brief	Prints a stack pair to the standard output.
 * 
 * @param	ss	the stack pair to print 
 */
void	stack_pair_print(t_stack_pair ss)
{
	int	k;
	int	len_a;
	int	len_b;

	if (ss.reversed)
	{
		stack_pair_reverse(&ss);
		stack_pair_print(ss);
		return ;
	}
	len_a = stack_len(ss.a);
	len_b = stack_len(ss.b);
	k = 0;
	stack_pair_print_left(ss.a, len_a - len_b);
	while (k++ < len_a - len_b)
		ss.a = ss.a->prev;
	stack_pair_print_right(ss.b, len_b - len_a);
	k = 0;
	while (k++ < len_b - len_a)
		ss.b = ss.b->prev;
	stack_pair_print_both(ss, ft_imin(len_a, len_b));
	ft_putendl("_____  _____");
}
