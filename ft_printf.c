/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:29 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/02/24 12:13:46 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char c, va_list args)
{
	if (c == 'c')
		return (print_charc(va_arg(args, int)));
	if (c == 's')
		return (print_strs(va_arg(args, char *)));
	if (c == 'p')
		return (print_pointp(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (print_intd(va_arg(args, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (print_hexl(va_arg(args, unsigned int)));
	if (c == 'X')
		return (print_hexu(va_arg(args, unsigned int)));
	if (c == '%')
	{
		print_charc('%');
		return (1);
	}
	print_charc(c);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else if (format[i] == '%')
		{
			count += check(format[i + 1], args);
			i++;
		}
		else
			count += print_charc(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
