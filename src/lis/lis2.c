/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:00:57 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 23:26:36 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Checks if an array of integers contains a given number.
 * 
 * @param arr	the array to be checked against.
 * @param N		the size of the array.
 * @param value	the value to search.
 * @return int	1 if the array contains the value, 0 otherwise.
 */
int	int_arr_contains(int *arr, int N, int value)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief	Applies a circular shift to a given array, moving each element to
 * 			the right by r positions.
 * 
 * @param	arr		the array to be shifted (in place).
 * @param	N		the size of the array.
 * @param	r		the number of positions to shift the array.
 * @return	int*	the shifted array.
 * 					NULL if the operation fails.
 */
int	*rotate_array(int **arr, int N, int r)
{
	int	*tmp;
	int	i;

	r %= N;
	if (r > 0)
		r -= N;
	tmp = malloc(sizeof(int) * N);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, *arr, sizeof(int) * N);
	i = 0;
	while (i < N)
	{
		(*arr)[i] = tmp[(i - r) % N];
		i++;
	}
	free(tmp);
	return (*arr);
}

/**
 * @brief	Calculates the longest increasing circular subsequence from a
 * 			given stack.
 * 
 * @param	stack 
 * @param	seq		the resulting subsequence (in array format),
 * 					passed by reference.
 * @return	int		the length of the longest increasing circular subsequence. 
 */
int	lics_stack(t_stack *stack, int **seq)
{
	int	*arr;
	int	len;
	int	n;

	arr = stack_array(stack);
	len = stack_len(stack);
	n = longest_increasing_circular_subsequence(arr, len, seq);
	free(arr);
	return (n);
}
