/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:50:06 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/30 18:56:32 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(int n)
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

static void	print_int(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			print_strs("-2147483648");
			return ;
		}
		print_charc('-');
		n *= -1;
	}
	if (n > 9)
	{
		print_intd(n / 10);
		print_intd(n % 10);
	}
	else
		print_charc(n + '0');
}

int	print_intd(int n)
{
	print_int(n);
	return (count(n));
}
