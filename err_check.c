/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 17:22:34 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/03 17:45:30 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	atoi_check(char *number)
{
	if (ft_atoi(number) == 0)
	{
		while (*number == ' ' || *number == '\n' || *number == '\t'
			|| *number == '\v' || *number == '\f' || *number == '\r')
			number++;
		if (*number == '+' || *number == '-')
			number++;
		if (!*number)
			return (0);
		while (*number)
		{
			if (*number != '0')
				return (0);
			number++;
		}
	}
	return (1);
}

static int	limit_check(char *number)
{
	while (*number <= ' ')
		number++;
	if (*number == '+')
		number++;
	if (*number == '-')
	{
		number++;
		while (*number == '0' && ft_isdigit(*(number + 1)))
			number++;
		if ((ft_strlen(number) == 10
				&& ft_strncmp(number, "2147483648", 10) > 0)
			|| ft_strlen(number) > 10)
			return (0);
		return (1);
	}
	while (*number == '0' && ft_isdigit(*(number + 1)))
		number++;
	if ((ft_strlen(number) == 10
			&& ft_strncmp(number, "2147483647", 10) > 0)
		|| ft_strlen(number) > 10)
		return (0);
	return (1);
}

int	err_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!atoi_check(argv[i]))
			return (0);
		if (!limit_check(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
