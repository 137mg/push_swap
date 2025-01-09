/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 16:52:43 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:45:08 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	dup_check(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == array[j] && i != j)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	make_stack(int argc, char **argv, t_stack **stack_a)
{
	int		*array;
	int		i;
	t_stack	*new;

	array = ft_calloc(argc - 1, sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (argv[i + 1])
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!dup_check(array, argc - 1))
		return (free(array), 0);
	i = 0;
	while (i < argc - 1)
	{
		new = b_stacknew(array[i]);
		if (!new)
			return (free(array), 0);
		b_stackadd_back(stack_a, new);
		i++;
	}
	return (free(array), 1);
}

static int	sort_check(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	if (stack_b)
		return (0);
	tmp = stack_a;
	while (tmp)
	{
		stack_a = tmp->next;
		if (stack_a && tmp->content > stack_a->content)
			return (0);
		tmp = stack_a;
	}
	return (1);
}

void	b_checker(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	if (!stack_a)
		return ;
	if (!make_stack(argc, argv, stack_a))
		return (b_free_stack(stack_a));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (!stack_b)
		return (b_free_stack(stack_a));
	if (!b_sort_stack(stack_a, stack_b))
		return (b_free_stack(stack_a), b_free_stack(stack_b));
	if (sort_check(*stack_a, *stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	b_free_stack(stack_a);
	b_free_stack(stack_b);
}
