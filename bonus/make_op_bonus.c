/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_op_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:11 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/01 12:57:25 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!*stack_2)
		return ;
	tmp = *stack_2;
	*stack_2 = tmp->next;
	b_stackadd_front(stack_1, tmp);
}

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	b_stackadd_front(stack, tmp);
}

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	b_stackadd_back(stack, tmp);
}

static void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = b_stacklast(*stack);
	tmp2 = *stack;
	while (tmp2->next && (tmp2->next)->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	b_stackadd_front(stack, tmp);
}

void	b_make_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	void	(*ft_op)(t_stack **);

	if (op[0] == 'p' && op[1] == 'a')
		return (push(stack_a, stack_b));
	if (op[0] == 'p' && op[1] == 'b')
		return (push(stack_b, stack_a));
	if (op[0] == 's')
		ft_op = swap;
	else if (op[0] == 'r' && !op[3])
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
