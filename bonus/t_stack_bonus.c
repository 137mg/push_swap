/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_stack_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:40 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/01 12:58:13 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*b_stacknew(int content)
{
	t_stack	*lst;

	lst = ft_calloc(1, sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	b_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = b_stacklast(*lst);
	last->next = new;
}

t_stack	*b_stacklast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

void	b_stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	b_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
