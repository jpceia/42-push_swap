/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:36:31 by jceia             #+#    #+#             */
/*   Updated: 2021/08/13 08:23:34 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"

static void	check_is_valid_integer(char *s)
{
	while (*s)
	{
		if (!(*s == '-' || *s == '+' || ft_isdigit(*s)))
			push_swap_error();
		s++;
	}
}

static int	parse_str_arg(char *s, int **arr)
{
	int		idx;
	int		N;
	int		nb;
	char	**s_arr;

	s_arr = ft_split(s, ' ');
	N = 0;
	while (s_arr[N])
		N++;
	*arr = malloc(sizeof(**arr) * N);
	if (!*arr)
		return (0);
	idx = 0;
	while (idx < N)
	{
		check_is_valid_integer(s_arr[idx]);
		nb = ft_atoi(s_arr[idx]);
		(*arr)[idx] = nb;
		idx++;
	}
	free(s_arr);
	return (N);
}

/*
 * TODO:
 *  check errors on stack_push
 *  check if input is number
 */
int	parse_args(char **args, int **arr)
{
	int	N;
	int	nb;
	int	idx;

	N = 0;
	*arr = NULL;
	while (args[N])
		N++;
	if (N < 1)
		return (0);
	if (N == 1)
		return (parse_str_arg(*args, arr));
	*arr = malloc(sizeof(**arr) * N);
	if (!*arr)
		return (0);
	idx = 0;
	while (idx < N)
	{
		check_is_valid_integer(args[idx]);
		nb = ft_atoi(args[idx]);
		(*arr)[idx] = nb;
		idx++;
	}
	return (N);
}
