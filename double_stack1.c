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

void	double_stack_print_line(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	ft_putstr_fd(s1, STDOUT_FILENO);
	while (8 > len++)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	ft_putstr_fd(s2, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	double_stack_print(t_stack *a, t_stack *b)
{
	size_t	idx;
	size_t	len_a;
	size_t	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	idx = 0;
	if (len_a > len_b)
	{
		while (len_a > len_b + idx)
		{
			double_stack_print_line(ft_itoa(a->value), "");
			idx++;
			a = a->prev;
		}
	}
	else
	{
		while (len_b > len_a + idx)
		{
			double_stack_print_line("", ft_itoa(b->value));
			idx++;
			b = b->prev;
		}
	}
	while (idx < MAX(len_a, len_b))
	{
		double_stack_print_line(ft_itoa(a->value), ft_itoa(b->value));
		idx++;
		a = a->prev;
		b = b->prev;
	}
	ft_putstr_fd("_______  _______\n", STDOUT_FILENO);
}

void	double_stack_init(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}

void	double_stack_free(t_stack **a, t_stack **b)
{
	stack_free(a);
	stack_free(b);
}
