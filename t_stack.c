/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_stack.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:26:40 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/03/25 16:39:25 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int content)
{
	t_stack	*lst;

	lst = ft_calloc(1, sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = stacklast(*lst);
	last->next = new;
}

t_stack	*stacklast(t_stack *lst)
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

void	stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	stacksize(t_stack *lst)
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
