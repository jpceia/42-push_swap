/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 05:02:28 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/12 16:00:50 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct s_params {
	int	len_a;
	int	len_b;
	int	pivot;
	int	pivot_val;
	int best_path;
	int min_steps;
	int	p;
	int q;
}				t_params;

void	push_swap_error(void);
int		parse_args(char **args, int **arr);
int		*arange(int start, int end);
int		*int_argsort(int *arr, size_t N);
int		*rankify(int **arr_ref, size_t N);
int		*reverse(int **arr_ref, size_t N);
int		arr_all_different(int *arr, size_t N);
int		stack_is_sorted(t_stack *stack);
t_stack	*stack_push_array(t_stack **stack, int *arr, size_t N);
void	radix_sort(t_stack *stack);
void	greedy_sort(t_stack *stack);
void	small_sort(t_stack *stack);
int		longest_increasing_subsequence(int *arr, int N, int **seq);
int		longest_increasing_circular_subsequence(int *arr, int N, int **seq);
int		int_arr_contains(int *arr, int N, int value);
int		*rotate_array(int **arr, int N, int r);
#endif
