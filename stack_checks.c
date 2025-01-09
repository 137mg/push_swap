/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:33:28 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/03/28 20:04:48 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == n)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	rr_check(t_stack *stack, int min, int max, int size)
{
	int	i_min;
	int	i_max;

	if (find_index(stack, min) < find_index(stack, max))
	{
		i_min = find_index(stack, min);
		i_max = find_index(stack, max);
	}
	else
	{
		i_min = find_index(stack, max);
		i_max = find_index(stack, min);
	}
	if (i_min == -1)
	{
		if (i_max > size / 2)
			return (1);
		return (0);
	}
	if (i_max > size / 2)
		if (i_min > size / 2 || i_min > size - i_max)
			return (1);
	return (0);
}

int	sort_check(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		stack = tmp->next;
		if (stack && tmp->content > stack->content)
			return (0);
		tmp = stack;
	}
	return (1);
}
