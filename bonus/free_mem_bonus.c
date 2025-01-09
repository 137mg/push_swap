/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_mem_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:03 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:45:21 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*b_free_chrarray(bool is_alloc, char **array)
{
	int	i;

	i = 0;
	if (is_alloc == true && array)
	{
		if (array[0][0] == '.')
			i++;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	return (NULL);
}

static void	b_free_node(t_stack *node)
{
	node->content = 0;
	node->next = NULL;
	free(node);
}

void	b_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			b_free_node(*stack);
			*stack = tmp;
		}
		free(stack);
	}
}
