/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:59:04 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/30 18:58:13 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	print_uint(unsigned int n)
{
	if (n > 9)
	{
		print_intd(n / 10);
		print_intd(n % 10);
	}
	else
		print_charc(n + '0');
}

int	print_intu(unsigned int n)
{
	print_uint(n);
	return (count(n));
}
