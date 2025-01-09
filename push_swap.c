/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:29:12 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:42:19 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_node(t_stack *node)
{
	node->content = 0;
	node->next = NULL;
	free(node);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free_node(*stack);
			*stack = tmp;
		}
		free(stack);
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	if (!stack_a)
		return ;
	if (!make_stack(argc, argv, stack_a))
		return (free_stack(stack_a));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (!stack_b)
		return (free_stack(stack_a));
	if (argc - 1 < 8)
		sort_small(stack_a, stack_b, argc - 1);
	else if (argc - 1 < 174)
		sort_medium(stack_a, stack_b, argc - 1);
	else
		sort_large(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
