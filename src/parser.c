/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:36:31 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 23:55:48 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include <limits.h>

/**
 * @brief	Checks if a string corresponds to a valid integer.
 * 
 * @param	s	the string to be checked.
 * @return	int	1 if the string is a valid integer, 0 otherwise. 
 */
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

/**
 * @brief	Converts a single string to an array of integers.
 * 			The resulting allocated on the heap and is passed by reference.
 * 
 * @param	s	the string to be parsed	
 * @param	arr	the reference to the array of integers where the result will
 * 				be stored. 
 * @return	int	1 if the string was successfully parsed, 0 otherwise.
 */
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

/**
 * @brief	Parses the arguments passed to the program and stores the result
 * 			in an array of integers, being passed by reference.
 * 			
 * @param	args	the arguments passed to the program. 
 * @param	arr		the reference to the array of integers where the result
 * 					will be stored. 
 * @return	int		1 if the arguments were successfully parsed, 0 otherwise.
 */
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
