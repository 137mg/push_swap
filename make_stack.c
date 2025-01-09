/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:20 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:43:18 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_min(long *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] < array[i])
				break ;
			j++;
		}
		if (j == size)
			return (i);
		i++;
	}
	return (-1);
}

static long	*make_i_array(long *array, int size)
{
	int	i;
	int	i_min;

	i = 0;
	i_min = index_min(array, size);
	while (i_min != -1 && array[i_min] <= (long)(INT_MAX))
	{
		array[i_min] = (long)(INT_MAX) + 1 + i;
		i++;
		i_min = index_min(array, size);
	}
	if (i_min == -1)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] -= ((long)(INT_MAX) + 1);
		i++;
	}
	return (array);
}

static int	array_check(long *array, int size)
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
				return (write(2, "Error\n", 6), 0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static long	*make_array(char **argv, int size)
{
	long	*array;
	int		i;

	array = ft_calloc(size, sizeof(long));
	if (!array)
		return (NULL);
	i = 0;
	while (argv[i + 1])
	{
		array[i] = (long) ft_atoi(argv[i + 1]);
		i++;
	}
	if (!array_check(array, size))
		return (free(array), NULL);
	if (size < 8)
		return (array);
	array = make_i_array(array, size);
	if (!array)
		return (free(array), NULL);
	return (array);
}

int	make_stack(int argc, char **argv, t_stack **stack_a)
{
	long	*array;
	int		i;
	t_stack	*new;

	array = make_array(argv, argc - 1);
	if (!array)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		new = stacknew((int) array[i]);
		if (!new)
			return (free(array), 0);
		stackadd_back(stack_a, new);
		i++;
	}
	return (free(array), 1);
}
