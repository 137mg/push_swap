/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:05:15 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/04/01 14:49:45 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculator(const char *str, int x, int y)
{
	int	n;

	n = 0;
	while (y != 0)
	{
		n += (*str - '0') * x;
		x *= 10;
		str--;
		y--;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			x *= -1;
		str++;
	}
	while (*str == '0' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str))
	{
		y++;
		str++;
	}
	if (*str)
		return (0);
	return (calculator((str - 1), x, y));
}
