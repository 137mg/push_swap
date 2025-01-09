/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   va_makers.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 14:21:39 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2022/11/10 14:17:54 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_maker(char chr, long n, int i)
{
	unsigned int	u;

	if (n < 0)
	{
		n = -n;
		u = (2147483648 - n) * 2 + n;
		if (chr == 'x' || chr == 'X')
			return (x_printer(chr, u, i));
		n = u;
	}
	i = int_printer(n, i);
	return (i);
}

int	p_maker(va_list ap, int i)
{
	void	*p;
	int		w;

	p = va_arg(ap, void *);
	w = write(1, "0x", 2);
	if (w == -1)
		return (-1);
	i += 2;
	if (p < 0)
		return (u_maker('x', (long) p, i));
	return (x_printer(0, (unsigned long) p, i));
}
