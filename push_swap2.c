#include "push_swap.h"
#include "double_stack.h"

void	small_sort(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	double_stack_print(a, b);
}

static void	greedy_sort_start(t_stack **a, t_stack **b)
{
	int	x;
	int	k;
	int	N;

	N = stack_len(*a);
	k = 0;
	while (k < N)
	{
		x = stack_top(*a);
		operation_pb(a, b);
		if (x < N / 2)
			operation_rb(a, b);
		k++;
	}
}

static int	get_position(t_stack *stack, int val, int pivot)
{
	int	i;
	int	k;
	int	len;

	len = stack_len(stack);
	k = 0;
	while (k++ < len)
	{
		i = (pivot + k) % len;
		if (val > stack_at(stack, i))
			return ((i - 1) % len);
	}
	return ((pivot - 1) % len);
}

static void	select_best_path(int steps[4], int index[2], int *min_steps, int *best_path, int *p, int *q)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (steps[k] < *min_steps)
		{
			*min_steps = steps[k];
			*p = index[1];
			*q = index[0];
			*best_path = k;
		}
		k++;
	}
}

static int	best_insertion(t_stack *a, t_stack *b, int pivot, int *p, int *q)
{
	int	idx[2];
	int	len[2];
	int	min_steps;
	int	best_path;
	int	steps[4];

	len[0] = stack_len(a);
	len[1] = stack_len(b);
	min_steps = len[0] + len[1] + 1;
	idx[1] = 0;
	while (idx[1] < len[1])
	{
		idx[0] = get_position(a, b->value, pivot);
		steps[0] = MAX(len[0] - idx[0], len[1] - idx[1]) - 1;
		steps[1] = MAX(idx[0], idx[1]) + 1;
		steps[2] = len[1] - idx[1] + idx[0];
		steps[3] = len[0] + idx[1] - idx[0];
		select_best_path(steps, &min_steps, idx, &best_path, p, q);
		b = b->prev;
		idx[1]++;
	}
	return (best_path);
}

static int	insert_top_top(t_stack **a, t_stack **b, int pivot, int p, int q)
{
	int	k;
	int	len_a;
	int	len_b;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	k = 0;
	if (len_a - q < len_b - p)
	{
		while (k++ < len_a - q - 1)
			operation_rr(a, b);
		k = 0;
		while (k++ < len_b - len_a - p + q)
			operation_rb(a, b);
	}
	else
	{
		while (k++ < len_b - p - 1)
			operation_rr(a, b);
		k = 0;
		while (k++ < len_a - len_b - q + p)
			operation_ra(a, b);
	}
	return (pivot + len_a - q - 1);
}

static int	insert_bottom_bottom(t_stack **a, t_stack **b, int pivot, int p, int q)
{
	int	k;

	k = 0;
	if (q > p)
	{
		while (k++ < p + 1)
			operation_rrr(a, b);
		k = 0;
		while (k++ < q - p)
			operation_rra(a, b);
	}
	else
	{
		while (k++ < q + 1)
			operation_rrr(a, b);
		k = 0;
		while (k++ < p - q)
			operation_rra(a, b);
	}
	return (pivot - q - 1);
}

static int	insert_bottom_top(t_stack **a, t_stack **b, int pivot, int p, int q)
{
	int	k;
	int	len_a;

	len_a = stack_len(*a);
	k = 0;
	while (k++ < p + 1)
		operation_rrb(a, b);
	k = 0;
	while (k++ < q + 1)
		operation_rra(a, b);
	return (pivot + len_a - q - 1);
}

static int	insert_top_bottom(t_stack **a, t_stack **b, int pivot, int p, int q)
{
	int	k;
	int	len_b;

	len_b = stack_len(*b);
	k = 0;
	while (k++ < len_b - p - 1)
		operation_rb(a, b);
	k = 0;
	while (k++ < q + 1)
		operation_rra(a, b);
	return (pivot - q - 1);
}

static int	apply_best_insertion(t_stack **a, t_stack **b, int path, int pivot, int p, int q)
{
	if (path == 0)
		return (insert_top_top(a, b, pivot, p, q));
	if (path == 1)
		return (insert_bottom_bottom(a, b, pivot, p, q));
	if (path == 2)
		return (insert_top_bottom(a, b, pivot, p, q));
	if (path == 3)
		return (insert_bottom_top(a, b, pivot, p, q));
	return (-1);
}

static void	greedy_sort_insertion_step(t_stack **a, t_stack **b, int *pivot, int *pivot_val)
{
	int	p;
	int	q;
	int	len_a;
	int	len_b;
	int	path;
	int	new_val;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	path = best_insertion(*a, *b, *pivot, &p, &q);
	new_val = stack_at(*b, len_b - p - 1);
	*pivot = apply_best_insertion(a, b, path, *pivot, p, q);
	if (new_val > *pivot_val)
	{
		*pivot = len_a;
		*pivot_val = new_val;
	}
	else
		*pivot %= len_a;
}

static void	greedy_sort_mid(t_stack **a, t_stack **b)
{
	int	k;
	int	len_a;
	int	len_b;
	int	pivot;
	int	pivot_val;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	pivot = len_a - 1 - stack_argmax(*a);
	pivot_val = stack_max(*a);
	k = 0;
	while (k++ < (int)len_b)
	{
		greedy_sort_insertion_step(a, b, &pivot, &pivot_val);
		operation_pa(a, b);
	}
}

static void	greedy_sort_finalize(t_stack **a, t_stack **b)
{
	int	len_a;
	int	pivot;

	len_a = stack_len(*a);
	pivot = len_a - stack_argmax(*a) - 1;
	if (pivot < len_a / 2)
	{
		while (pivot-- > 0)
			operation_rra(a, b);
	}
	else
	{
		while (len_a > pivot++)
			operation_ra(a, b);
	}
}

void	greedy_sort(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	greedy_sort_start(&a, &b);
	greedy_sort_mid(&a, &b);
	greedy_sort_finalize(&a, &b);
}
