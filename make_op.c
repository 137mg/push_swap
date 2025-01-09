/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_op.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:11 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/03 19:28:49 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	tmp = *stack_2;
	*stack_2 = tmp->next;
	stackadd_front(stack_1, tmp);
}

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	stackadd_front(stack, tmp);
}

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	stackadd_back(stack, tmp);
}

static void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stacklast(*stack);
	tmp2 = *stack;
	while (tmp2->next && (tmp2->next)->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	stackadd_front(stack, tmp);
}

void	make_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	void	(*ft_op)(t_stack **);

	ft_printf("%s\n", op);
	if (op[0] == 'p' && op[1] == 'a')
		return (push(stack_a, stack_b));
	if (op[0] == 'p' && op[1] == 'b')
		return (push(stack_b, stack_a));
	if (op[0] == 's')
		ft_op = swap;
	else if (op[0] == 'r' && !op[2])
		ft_op = rotate;
	else
	{
		ft_op = r_rotate;
		op++;
	}
	if (op[1] == 'a')
		return (ft_op(stack_a));
	if (op[1] == 'b')
		return (ft_op(stack_b));
	return (ft_op(stack_a), ft_op(stack_b));
}
