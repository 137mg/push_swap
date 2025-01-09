/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:23:29 by mgoedkoo      #+#    #+#                 */
/*   Updated: 2023/02/13 16:31:12 by mgoedkoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	char_decider(char chr, va_list ap, int i);
int	int_printer(long n, int i);
int	ft_printf(const char *s, ...);
int	int_decider(char chr, va_list ap, int i);
int	p_maker(va_list ap, int i);
int	s_printer(char *s, int i);
int	u_maker(char chr, long n, int i);
int	va_decider(char chr, va_list ap, int i);
int	x_printer(char chr, unsigned long x, int i);

#endif