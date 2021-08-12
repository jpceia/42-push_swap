/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:02:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/12 12:45:14 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(-1);
}

int	*arange(int start, int end)
{
	int	index;
	int	*arr;

	if (start >= end)
		return (NULL);
	arr = malloc(sizeof(*arr) * (end - start));
	index = 0;
	while (start + index < end)
	{
		arr[index] = start + index;
		index++;
	}
	return (arr);
}

int	*int_argsort(int *arr, size_t N)
{
	int	*index;
	int	i;
	int	j;
	int	holder;

	index = arange(0, N);
	if (!index)
		return (NULL);
	i = 0;
	while (i + 1 < (int)N)
	{
		j = i + 1;
		while (j < (int)N)
		{
			if (arr[index[j]] < arr[index[i]])
			{
				holder = index[i];
				index[i] = index[j];
				index[j] = holder;
			}
			j++;
		}
		i++;
	}
	return (index);
}

int	*rankify(int **arr_ref, size_t N)
{
	int	k;
	int	*index;

	index = int_argsort(*arr_ref, N);
	k = 0;
	while (k < (int)N)
	{
		(*arr_ref)[index[k]] = k;
		k++;
	}
	free(index);
	return (*arr_ref);
}
