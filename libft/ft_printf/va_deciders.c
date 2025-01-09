/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   va_deciders.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 15:01:16 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2022/11/10 14:15:32 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_decider(char chr, va_list ap, int i)
{
	char	c;
	int		w;

	if (chr == 's')
		return (s_printer(va_arg(ap, char *), i));
	if (chr == 'c')
		c = va_arg(ap, int);
	if (chr == '%')
		c = '%';
	w = write(1, &c, 1);
	if (w == -1)
		return (-1);
	i++;
	return (i);
}

int	int_decider(char chr, va_list ap, int i)
{
	int	v;

	if (chr == 'd' || chr == 'i')
	{
		v = (long) va_arg(ap, int);
		i = int_printer(v, i);
	}
	if (chr == 'u')
	{
		v = (long) va_arg(ap, int);
		i = u_maker(chr, v, i);
	}
	return (i);
}

int	va_decider(char chr, va_list ap, int i)
{
	int	v;

	if (chr == 'c' || chr == 's' || chr == '%')
		i = char_decider(chr, ap, i);
	if (chr == 'd' || chr == 'i' || chr == 'u')
		i = int_decider(chr, ap, i);
	if (chr == 'p')
		i = p_maker(ap, i);
	if (chr == 'x' || chr == 'X')
	{
		v = va_arg(ap, int);
		if (v < 0)
			i = u_maker(chr, v, i);
		else
			i = x_printer(chr, (unsigned int) v, i);
	}
	return (i);
}
