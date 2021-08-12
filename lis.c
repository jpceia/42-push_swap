/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:38:19 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/10 02:36:13 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ceil_index(int *arr, int *index, int x, int key)
{
	int	y;
	int	m;

	y = -1;
	while (x - y > 1)
	{
		m = x + (y - x) / 2;
		if (arr[index[m]] >= key)
			y = m;
		else
			x = m;
	}
	return (y);
}

static int *build_LIS(int *arr, int *prev_indices, int start, int **seq)
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

static int	longest_increasing_subsequence_aux(int *arr, int N, int *tail_indices, int *prev_indices)
{
	int i;
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
	int *success;
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
	length = longest_increasing_subsequence_aux(arr, N, tail_indices, prev_indices);
	success = build_LIS(arr, prev_indices, tail_indices[length - 1], seq);
	free(prev_indices);
	free(tail_indices);
	if (success)
		return (length);
	return (0);
}

int	*rotate_array(int **arr, int N, int r)
{
	int *tmp;
	int i;

	tmp = malloc(sizeof(int) * N);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < N)
	{
		tmp[i] = (*arr)[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		(*arr)[i] = tmp[(i - r) % N];
		i++;
	}
	free(tmp);
	return (*arr);
}

int longest_increasing_circular_subsequence(int *arr, int N, int **seq)
{
	int *tmp_seq;
	int i;
	int len;
	int max_length;

	i = 0;
	max_length = 0;
	while (i < N)
	{
		rotate_array(&arr, N, i);
		len = longest_increasing_subsequence(arr, N, &tmp_seq);
		rotate_array(&arr, N, -i);
		if (len > max_length)
		{
			if (*seq)
				free(*seq);
			max_length = len;
			*seq = tmp_seq;
		}
		else
			free(tmp_seq);
		i++;
	}
	return (max_length);
}

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
