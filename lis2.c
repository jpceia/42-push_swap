/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:00:57 by jceia             #+#    #+#             */
/*   Updated: 2021/09/20 15:10:37 by jceia            ###   ########.fr       */
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
