/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:02:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 05:25:05 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"

int	*reverse(int **arr_ref, size_t N)
{
	int	k;
	int	holder;

	k = 0;
	while (k < (int)(N / 2))
	{
		holder = (*arr_ref)[k];
		(*arr_ref)[k] = (*arr_ref)[N - k - 1];
		(*arr_ref)[N - k - 1] = holder;
		k++;
	}
	return (*arr_ref);
}

int	arr_all_different(int *arr, size_t N)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)(N - 1))
	{
		j = i + 1;
		while (j < (int)N)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
