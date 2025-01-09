/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 18:30:03 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2022/11/08 12:37:34 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		w;

	va_start(ap, str);
	i = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			i = va_decider(*str, ap, i);
		}
		else
		{
			w = write(1, str, 1);
			i++;
		}
		if (i == -1 || w == -1)
			return (-1);
		str++;
	}
	va_end(ap);
	return (i);
}
