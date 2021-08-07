#include "stack.h"
#include "double_stack.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		nb;
	int		idx;
	t_stack *a, *b;

	a = NULL;
	b = NULL;
	idx = 1;
	while (idx < argc)
	{
		nb = ft_atoi(argv[idx]);
		stack_push(&a, nb);
		idx++;
	}
	print_double_stack(a, b);
	operation_pb(&a, &b);
	operation_rb(&a, &b);
	print_double_stack(a, b);
}