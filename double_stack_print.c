/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:23:29 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/08 01:32:28 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

static void	double_stack_print_line(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	ft_putstr_fd(s1, STDOUT_FILENO);
	while (6 > len++)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	ft_putstr_fd(s2, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	double_stack_print_both(t_stack *a, t_stack *b, size_t N)
{
	char	*s1;
	char	*s2;

	while (N--)
	{
		s1 = ft_itoa(a->value);
		s2 = ft_itoa(b->value);
		double_stack_print_line(s1, s2);
		free(s1);
		free(s2);
		a = a->prev;
		b = b->prev;
	}
}

static void	double_stack_print_left(t_stack *stack, size_t N)
{
	char	*s;

	while (N--)
	{
		s = ft_itoa(stack->value);
		double_stack_print_line(s, "");
		free(s);
		stack = stack->prev;
	}
}

static void	double_stack_print_right(t_stack *stack, size_t N)
{
	char	*s;

	while (N--)
	{
		s = ft_itoa(stack->value);
		double_stack_print_line("", s);
		free(s);
		stack = stack->prev;
	}
}

void	double_stack_print(t_stack *a, t_stack *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	if (len_a > len_b)
	{
		double_stack_print_left(a, len_a - len_b);
		while (--len_a > len_b)
			a = a->prev;
	}
	else
	{
		double_stack_print_right(b, len_b - len_a);
		while (--len_b > len_a)
			b = b->prev;
	}
	double_stack_print_both(a, b, len_a);
	ft_putstr_fd("_____  _____\n", STDOUT_FILENO);
}
