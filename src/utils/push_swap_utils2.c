/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:02:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 21:57:28 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "libft.h"

/**
 * @brief	Reverses a given array of integers, by reference.
 * 
 * @param	arr_ref	The array to be reversed.
 * @param	N		The size of the array.
 * @return	int*	The reversed array.
 */
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

/**
 * @brief	Checks if all the elements of an array of integers are distinct.
 * 
 * @param	arr	The array to be checked. 
 * @param	N	The size of the array. 
 * @return	int	1 if all elements are distinct, 0 otherwise.
 */
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
			{
				free(arr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
