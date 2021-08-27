/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:36:31 by jceia             #+#    #+#             */
/*   Updated: 2021/08/27 21:53:08 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include <limits.h>

static int	check_is_valid_integer(char *s)
{
	long	nb;

	if (ft_strlen(s) > 11)
		return (0);
	nb = ft_atol(s);
	if (nb > (long)(INT_MAX) || nb < (long)(INT_MIN))
		return (0);
	while (*s)
	{
		if (!(*s == '-' || *s == '+' || ft_isdigit(*s)))
			return (0);
		s++;
	}
	return (1);
}

static int	parse_str_arg(char *s, int **arr)
{
	int		idx;
	int		N;
	char	**s_arr;

	s_arr = ft_split(s, ' ');
	N = 0;
	while (s_arr[N])
		N++;
	*arr = malloc(sizeof(**arr) * N);
	if (!*arr)
		return (-1);
	idx = 0;
	while (idx < N)
	{
		if (!check_is_valid_integer(s_arr[idx]))
		{
			free(s_arr);
			return (-1);
		}
		(*arr)[idx] = ft_atoi(s_arr[idx]);
		idx++;
	}
	free(s_arr);
	return (N);
}

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
		return (-1);
	idx = 0;
	while (idx < N)
	{
		if (!check_is_valid_integer(args[idx]))
			return (-1);
		nb = ft_atoi(args[idx]);
		(*arr)[idx] = nb;
		idx++;
	}
	return (N);
}
