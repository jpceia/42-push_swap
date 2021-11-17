/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:20:00 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 22:59:06 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "push_swap.h"
#include "libft.h"

/**
 * @brief Applies a given operation to the stack pair.
 * 
 * @param ss	the stack pair to be operated.
 * @param line	a string containing the operation to be applied.
 * @return int	0 if the operation was applied successfully, -1 otherwise.
 */
int	apply_operations_step(t_stack_pair *ss, char *line)
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
		return (-1);
	return (0);
}

/**
 * @brief	Applies a sequence of operations to the stack pair.
 * 			The stream operations are read from the file descriptor.
 * 
 * @param	a	a reference to the stack to be operated.
 * @param	fd	the file descriptor to read the operations from.
 * @return int	0 if the operations were applied successfully, -1 otherwise.
 */
int	apply_operations(t_stack **a, int fd)
{
	t_stack_pair	ss;
	int				status;
	char			*line;

	stack_pair_init(&ss);
	ss.a = *a;
	status = 0;
	while (ft_get_next_line(fd, &line) > 0 && status == 0)
	{
		status = apply_operations_step(&ss, line);
		free(line);
	}
	free(line);
	if (status < 0)
	{
		stack_pair_clear(&ss);
		return (-1);
	}
	else
		stack_clear(ss.b);
	*a = ss.a;
	return (0);
}

/**
 * @brief	Main function for the checker.
 * 
 * @param argc	number of arguments.
 * @param argv	array of arguments.
 * @return int	resulting status.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		n;

	(void)argc;
	stack_a = NULL;
	n = parse_args(argv + 1, &arr);
	if (n <= 0 && arr != NULL)
		free(arr);
	if (n == 0)
		return (EXIT_SUCCESS);
	if (arr == NULL || n < 0 || !arr_all_different(arr, n))
		push_swap_error();
	reverse(&arr, n);
	rankify(&arr, n);
	stack_push_array(&stack_a, arr, n);
	if (apply_operations(&stack_a, STDIN_FILENO) < 0)
		push_swap_error();
	else if (stack_is_sorted(stack_a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_clear(stack_a);
	return (EXIT_SUCCESS);
}
