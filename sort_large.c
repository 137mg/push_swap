/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:33 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/01 14:30:51 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_bin(int n, int power)
{
	while (power > 0)
	{
		n /= 2;
		power--;
	}
	n %= 2;
	return (n);
}

static int	zero_check(t_stack *stack, int i)
{
	t_stack	*tmp;
	int		bin;

	while (stack)
	{
		bin = make_bin(stack->content, i);
		if (bin == 0)
			return (1);
		tmp = stack->next;
		stack = tmp;
	}
	return (0);
}

static int	one_check(t_stack *stack, int i)
{
	t_stack	*tmp;
	int		bin;

	while (stack)
	{
		bin = make_bin(stack->content, i);
		if (bin == 1)
			return (1);
		tmp = stack->next;
		stack = tmp;
	}
	return (0);
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	bin;
	int	first;
	int	p;

	p = 0;
	while (!sort_check(*stack_a))
	{
		first = -1;
		while (*stack_a && zero_check(*stack_a, p) && one_check(*stack_a, p))
		{
			bin = make_bin((*stack_a)->content, p);
			if (first == -1 && bin == 1)
				first = (*stack_a)->content;
			if (bin == 0)
				make_op("pb", stack_a, stack_b);
			else
				make_op("ra", stack_a, NULL);
		}
		while ((*stack_a)->content != first)
			make_op("ra", stack_a, NULL);
		while (*stack_b)
			make_op("pa", stack_a, stack_b);
		p++;
	}
}
