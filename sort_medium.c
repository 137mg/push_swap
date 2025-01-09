/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 18:23:37 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/03/30 18:32:16 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_stack **stack_a, t_stack **stack_b, int tmp_size)
{
	int	i_max;

	while (*stack_b)
	{
		i_max = find_index(*stack_b, tmp_size - 4);
		if (i_max > stacksize(*stack_b) / 2)
		{
			while ((*stack_b)->content != tmp_size - 4)
				make_op("rrb", NULL, stack_b);
			make_op("pa", stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)->content != tmp_size - 4)
				make_op("rb", NULL, stack_b);
			make_op("pa", stack_a, stack_b);
		}
		tmp_size--;
	}
}

static void	push_b(t_stack **stack_a, t_stack **stack_b, int size, int tmp_size)
{
	int	half_size;
	int	start;

	while (*stack_a && tmp_size > 4)
	{
		half_size = tmp_size / 2;
		if (tmp_size % 2 == 1)
			half_size++;
		start = -1;
		while ((*stack_a)->content != start && tmp_size > 4)
		{
			if ((*stack_a)->content <= size - half_size - 1)
			{
				make_op("pb", stack_a, stack_b);
				tmp_size--;
			}
			else
			{
				if (start == -1)
					start = (*stack_a)->content;
				make_op("ra", stack_a, NULL);
			}
		}
	}
}

void	sort_medium(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	tmp_size;

	tmp_size = size;
	push_b(stack_a, stack_b, size, tmp_size);
	while ((*stack_a)->content > size - 4)
		make_op("ra", stack_a, NULL);
	make_op("pb", stack_a, stack_b);
	sort_three(stack_a, 3);
	push_a(stack_a, stack_b, tmp_size);
}
