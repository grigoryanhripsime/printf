/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:19 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/30 18:55:53 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_count(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count ++;
		n = n / 16;
	}
	return (count);
}

static void	print_hexlower(unsigned int n)
{
	if (n > 15)
	{
		print_hexl(n / 16);
		print_hexl(n % 16);
	}
	else
	{
		if (n > 9)
			print_charc(n + 'a' - 10);
		else
			print_charc(n + '0');
	}
}

int	print_hexl(unsigned int n)
{
	print_hexlower(n);
	return (hex_count(n));
}

static void	print_hexupper(unsigned int n)
{
	if (n > 15)
	{
		print_hexu(n / 16);
		print_hexu(n % 16);
	}
	else
	{
		if (n > 9)
			print_charc(n + 'A' - 10);
		else
			print_charc(n + '0');
	}
}

int	print_hexu(unsigned int n)
{
	print_hexupper(n);
	return (hex_count(n));
}
