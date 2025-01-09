/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stack_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 17:22:27 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:46:25 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	op_check(const char *op, int len)
{
	if (len < 3 || len > 4)
		return (0);
	if (op[len - 1] != '\n')
		return (0);
	if (len == 3)
	{
		if (op[0] != 'p' && op[0] != 's' && op[0] != 'r')
			return (0);
		if (op[0] == 'p')
			if (op[1] != 'a' && op[1] != 'b')
				return (0);
		if (op[0] == 's' || op[0] == 'r')
			if (op[1] != 'a' && op[1] != 'b' && op[1] != op[0])
				return (0);
	}
	if (len == 4)
	{
		if (op[0] != 'r' || op[1] != 'r')
			return (0);
		if (op[2] != 'a' && op[2] != 'b' && op[2] != 'r')
			return (0);
	}
	return (1);
}

int	b_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			return (0);
		if (!op[0])
			return (free(op), 1);
		if (!op_check(op, ft_strlen(op)))
		{
			write(2, "Error\n", 6);
			return (free(op), 0);
		}
		b_make_op(op, stack_a, stack_b);
		free(op);
		op = NULL;
	}
	return (0);
}
