/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:00:57 by jceia             #+#    #+#             */
/*   Updated: 2021/08/14 20:39:10 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

int	LICS_stack(t_stack *stack, int **seq)
{
	int	*arr;
	int	len;
	int	N;

	arr = stack_array(stack);
	len = stack_len(stack);
	N = longest_increasing_circular_subsequence(arr, len, seq);
	free(arr);
	return (N);
}
