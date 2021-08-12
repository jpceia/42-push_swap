/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 05:02:28 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/12 12:10:14 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void	push_swap_exit();
int		parse_args(char **args, int **arr);
int		*arange(int start, int end);
int		*int_argsort(int *arr, size_t N);
int		*rankify(int **arr_ref, int N);
int		*reverse(int **arr_ref, size_t N);
int		arr_all_different(int *arr, int N);
int		stack_is_sorted(t_stack *stack);
t_stack	*stack_push_array(t_stack **stack, int *arr, size_t N);
void	radix_sort(t_stack *stack);
void	greedy_sort(t_stack *stack);
void	small_sort(t_stack *stack);
int		longest_increasing_subsequence(int *arr, int N, int **seq);
int		longest_increasing_circular_subsequence(int *arr, int N, int **seq);
int		int_arr_contains(int *arr, int N, int value);
#endif
