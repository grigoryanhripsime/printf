/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:17:43 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/30 18:54:04 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	long_hex_count(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count ++;
		n = n / 16;
	}
	return (count);
}

static char	to_char(int n)
{
	if (n >= 10)
		return (n + 'a' - 10);
	return (n + '0');
}

static void	print_long_hex(unsigned long n)
{
	if (n > 15)
	{
		print_long_hex(n / 16);
		print_long_hex(n % 16);
	}
	else
		print_charc(to_char(n));
}

int	print_pointp(void *p)
{
	unsigned long	add;

	add = (unsigned long) p;
	print_strs("0x");
	print_long_hex(add);
	return (2 + long_hex_count(add));
}
