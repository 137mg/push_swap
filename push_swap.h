/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:29:10 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:43:00 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		err_check(char **argv);
int		find_index(t_stack *stack, int n);
void	stackadd_back(t_stack **lst, t_stack *new);
void	stackadd_front(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
t_stack	*stacknew(int content);
int		stacksize(t_stack *lst);
void	make_op(char *op, t_stack **stack_a, t_stack **stack_b);
int		make_stack(int argc, char **argv, t_stack **stack_a);
void	push_swap(int argc, char **argv);
int		rr_check(t_stack *stack, int min, int max, int size);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
void	sort_medium(t_stack **stack_a, t_stack **stack_b, int size);
int		sort_check(t_stack *stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_three(t_stack **stack_a, int size);

#endif