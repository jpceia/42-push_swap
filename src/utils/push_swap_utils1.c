/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:02:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 23:34:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief	Exits the program with a message to stderr.
 * 
 */
void	push_swap_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/**
 * @brief	Creates an array of consecutive integers, from start to end.
 * 
 * @param	start	the start value. 
 * @param	end		the end value.
 * @return	int*	the array of consecutive integers.
 */
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

/**
 * @brief	Returns the indices that would sort an array.
 * 
 * @param	arr		the array to sort.
 * @param	N		the size of the array.
 * @return	int*	the indices that would sort `arr`.
 */
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

/**
 * @brief	Converts a value of an element of an array to its rank in the
 * 			array.
 * 
 * @param	arr		the array to be rankified.
 * @param	N		the size of the array.
 * @return	int*	the resulting rank array.
 */
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
