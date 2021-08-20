/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 05:02:28 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/20 23:34:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"
# include "stack_pair.h"
# include "greedy_sort.h"

void	push_swap_error(void);
int		parse_args(char **args, int **arr);
int		*arange(int start, int end);
int		*int_argsort(int *arr, size_t N);
int		*rankify(int **arr_ref, size_t N);
int		*reverse(int **arr_ref, size_t N);
int		arr_all_different(int *arr, size_t N);
void	radix_sort(t_stack *stack);
void	small_sort(t_stack *stack);
int		longest_increasing_subsequence(int *arr, int N, int **seq);
int		longest_increasing_circular_subsequence(int *arr, int N, int **seq);
int		LICS_stack(t_stack *stack, int **seq);
int		int_arr_contains(int *arr, int N, int value);
int		*rotate_array(int **arr, int N, int r);

#endif
