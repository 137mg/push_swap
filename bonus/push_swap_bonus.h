/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 16:34:36 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:45:28 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		b_err_check(char **argv);
void	*b_free_chrarray(bool is_malloc, char **array);
void	b_free_stack(t_stack **stack);
void	b_checker(int argc, char **argv);
void	b_make_op(char *op, t_stack **stack_a, t_stack **stack_b);
int		b_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	b_stackadd_back(t_stack **lst, t_stack *new);
void	b_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*b_stacklast(t_stack *lst);
t_stack	*b_stacknew(int content);
int		b_stacksize(t_stack *lst);

#endif