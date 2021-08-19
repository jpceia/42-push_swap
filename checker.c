/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checker.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jpceia <jpceia@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/13 08:25:24 by jpceia			#+#	#+#			 */
/*   Updated: 2021/08/13 09:29:12 by jpceia		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "double_stack.h"
#include "push_swap.h"
#include "get_next_line.h"
#include "libft_bonus.h"

void	checker_error(void)
{
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit(-1);
}

void	apply_operations_step(t_double_stack *ss, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		operation_pa(ss, false);
	else if (ft_strcmp(line, "pb") == 0)
		operation_pb(ss, false);
	else if (ft_strcmp(line, "sa") == 0)
		operation_sa(ss, false);
	else if (ft_strcmp(line, "sb") == 0)
		operation_sb(ss, false);
	else if (ft_strcmp(line, "ss") == 0)
		operation_ss(ss, false);
	else if (ft_strcmp(line, "ra") == 0)
		operation_ra(ss, false);
	else if (ft_strcmp(line, "rb") == 0)
		operation_rb(ss, false);
	else if (ft_strcmp(line, "rr") == 0)
		operation_rr(ss, false);
	else if (ft_strcmp(line, "rra") == 0)
		operation_rra(ss, false);
	else if (ft_strcmp(line, "rrb") == 0)
		operation_rrb(ss, false);
	else if (ft_strcmp(line, "rrr") == 0)
		operation_rrr(ss, false);
	else
		checker_error();
}

void	apply_operations(t_stack **a, int fd)
{
	t_double_stack	ss;
	char			*line;

	double_stack_init(&ss);
	ss.a = *a;
	while (get_next_line(fd, &line))
		apply_operations_step(&ss, line);
	stack_clear(ss.b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		N;

	(void)argc;
	N = parse_args(argv + 1, &arr);
	stack_a = NULL;
	if (arr == NULL)
		push_swap_error();
	if (!arr_all_different(arr, N))
		push_swap_error();
	reverse(&arr, N);
	rankify(&arr, N);
	if (!stack_push_array(&stack_a, arr, N))
		push_swap_error();
	apply_operations(&stack_a, STDIN_FILENO);
	if (stack_is_sorted(stack_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	stack_clear(stack_a);
}
