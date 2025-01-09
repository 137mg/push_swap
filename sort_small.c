/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 15:13:13 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/03 19:33:14 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, int size)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = ((*stack_a)->next)->content;
	if (size > 2)
		third = (((*stack_a)->next)->next)->content;
	if (size == 3 && !(third > first && third > second))
	{
		if (first > second && first > third)
			make_op("ra", stack_a, NULL);
		else
			make_op("rra", stack_a, NULL);
	}
	if (!sort_check(*stack_a))
		return (make_op("sa", stack_a, NULL));
}

static int	find_limits(t_stack *stack, int limit)
{
	int	min;
	int	max;

	min = stack->content;
	max = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	if (limit == 0)
		return (min);
	return (max);
}

static int	pb_limits(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min;
	int	max;
	int	new_size;

	min = find_limits(*stack_a, 0);
	max = find_limits(*stack_a, 1);
	new_size = size - 2;
	if (size == 4)
		new_size++;
	while (size > new_size)
	{
		if ((*stack_a)->content == min || (*stack_a)->content == max)
		{
			make_op("pb", stack_a, stack_b);
			size--;
		}
		else if (rr_check(*stack_a, min, max, size))
			make_op("rra", stack_a, NULL);
		else
			make_op("ra", stack_a, NULL);
	}
	return (size);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size > 3)
		size = pb_limits(stack_a, stack_b, size);
	if (!sort_check(*stack_a))
		sort_three(stack_a, size);
	while (*stack_b)
	{
		make_op("pa", stack_a, stack_b);
		if ((*stack_a)->content == find_limits(*stack_a, 1))
			make_op("ra", stack_a, NULL);
	}
}
