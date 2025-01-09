/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/25 19:02:16 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/06 20:40:05 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_chrarray(bool is_alloc, char **array)
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

static int	chrarray_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static char	**argv_split(char **argv)
{
	char	**new_argv;
	char	**split_argv1;
	int		i;

	split_argv1 = ft_split(argv[1], ' ');
	if (!split_argv1)
		return (NULL);
	new_argv = ft_calloc(chrarray_len(split_argv1) + 2, sizeof(char *));
	if (!new_argv)
		return (free_chrarray(true, split_argv1));
	new_argv[0] = argv[0];
	i = 0;
	while (split_argv1[i])
	{
		new_argv[i + 1] = split_argv1[i];
		i++;
	}
	new_argv[i + 1] = NULL;
	free(split_argv1);
	return (new_argv);
}

int	main(int argc, char **argv)
{
	bool	is_split;

	if (argc < 2)
		return (0);
	is_split = false;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		is_split = true;
		argv = argv_split(argv);
		if (!argv)
			return (0);
		argc = chrarray_len(argv);
	}
	if (argc == 2 || !err_check(argv))
	{
		if (!err_check(argv))
			write(2, "Error\n", 6);
		free_chrarray(is_split, argv);
		return (0);
	}
	push_swap(argc, argv);
	free_chrarray(is_split, argv);
	return (0);
}
