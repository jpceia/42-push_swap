/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:16:55 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/07 23:53:45 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "double_stack.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		nb;
	int		idx;
	t_stack *a, *b;

	double_stack_init(&a, &b);
	idx = 1;
	while (idx < argc)
	{
		nb = ft_atoi(argv[idx]);
		stack_push(&a, nb);
		idx++;
	}
	double_stack_print(a, b);
	/*
	operation_pb(&a, &b);
	operation_rb(&a, &b);
	double_stack_print(a, b);
	*/
}