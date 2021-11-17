/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:36:31 by jceia             #+#    #+#             */
/*   Updated: 2021/09/20 15:12:37 by jceia            ###   ########.fr       */
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
	if (!(*s == '-' || *s == '+' || ft_isdigit(*s)))
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	parse_str_arg(char *s, int **arr)
{
	int		idx;
	int		n;
	char	**s_arr;

	s_arr = ft_split(s, ' ');
	n = 0;
	while (s_arr[n])
		n++;
	*arr = malloc(sizeof(**arr) * n);
	if (!*arr)
		return (-1);
	idx = 0;
	while (idx < n)
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
	return (n);
}

int	parse_args(char **args, int **arr)
{
	int	n;
	int	nb;
	int	idx;

	n = 0;
	*arr = NULL;
	while (args[n])
		n++;
	if (n < 1)
		return (0);
	if (n == 1)
		return (parse_str_arg(*args, arr));
	*arr = malloc(sizeof(**arr) * n);
	if (!*arr)
		return (-1);
	idx = 0;
	while (idx < n)
	{
		if (!check_is_valid_integer(args[idx]))
			return (-1);
		nb = ft_atoi(args[idx]);
		(*arr)[idx] = nb;
		idx++;
	}
	return (n);
}
