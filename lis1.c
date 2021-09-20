/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:38:19 by jpceia            #+#    #+#             */
/*   Updated: 2021/09/20 15:10:43 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_ceil_index(int *arr, int *index, int r, int key)
{
	int	l;
	int	m;

	l = -1;
	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		if (arr[index[m]] >= key)
			r = m;
		else
			l = m;
	}
	return (r);
}

static int	*build_lis(int *arr, int *prev_indices, int start, int **seq)
{
	int	i;
	int	j;
	int	len;

	i = start;
	len = 0;
	while (i >= 0)
	{
		i = prev_indices[i];
		len++;
	}
	*seq = malloc(sizeof(int) * len);
	if (!*seq)
		return (NULL);
	i = start;
	j = len;
	while (i >= 0)
	{
		(*seq)[--j] = arr[i];
		i = prev_indices[i];
	}
	return (*seq);
}

static int	longest_increasing_subsequence_aux(
	int *arr, int N, int *tail_indices, int *prev_indices)
{
	int	i;
	int	pos;
	int	length;

	length = 1;
	i = 0;
	while (++i < N)
	{
		if (arr[i] < arr[tail_indices[0]])
			tail_indices[0] = i;
		else if (arr[i] > arr[tail_indices[length - 1]])
		{
			prev_indices[i] = tail_indices[length - 1];
			tail_indices[length++] = i;
		}
		else
		{
			pos = get_ceil_index(arr, tail_indices, length - 1, arr[i]);
			prev_indices[i] = tail_indices[pos - 1];
			tail_indices[pos] = i;
		}
	}
	return (length);
}

int	longest_increasing_subsequence(int *arr, int N, int **seq)
{
	int	length;
	int	*tail_indices;
	int	*prev_indices;

	tail_indices = ft_calloc(N, sizeof(int));
	if (!tail_indices)
		return (0);
	prev_indices = malloc(N * sizeof(int));
	if (!prev_indices)
		return (0);
	length = 0;
	while (length < N)
		prev_indices[length++] = -1;
	length = longest_increasing_subsequence_aux(
			arr, N, tail_indices, prev_indices);
	build_lis(arr, prev_indices, tail_indices[length - 1], seq);
	free(prev_indices);
	free(tail_indices);
	return (length);
}

int	longest_increasing_circular_subsequence(int *arr, int N, int **seq)
{
	int	*tmp;
	int	i;
	int	len;
	int	max_length;

	i = 0;
	max_length = 0;
	*seq = malloc(sizeof(int) * N);
	if (!*seq)
		return (0);
	while (i < N)
	{
		rotate_array(&arr, N, i);
		len = longest_increasing_subsequence(arr, N, &tmp);
		rotate_array(&arr, N, -i);
		if (len > max_length)
		{
			max_length = len;
			ft_memcpy(*seq, tmp, sizeof(int) * len);
		}
		free(tmp);
		i++;
	}
	return (max_length);
}
