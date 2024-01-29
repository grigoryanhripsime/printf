/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:17:43 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/29 19:30:32 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int long_hex_count(unsigned long n)
{
	int count;

	count = 0;
	while (n > 0)
	{
		count ++;
		n = n / 16;
	}
	return (count);
}

static char hex_charl(int n)
{
	if (n >= 10)
		return (n + 'a' - 10);
	return (n + '0');
}

static int print_long_hex(unsigned long n)
{
	int count;
	char* num;
	int i;

	i = 0;
	count = long_hex_count(n);
	num = malloc((count + 1) * sizeof(char));
	if (!num)
		return (0);
	while (i < count)
	{
		num[count - i - 1] = hex_charl(n % 16);
		n /= 16;
		i++;
	}
	num[count - i - 1] = '\0';
	print_strs(num);
	free(num);
	return (count);
}

int print_pointp(void *p)
{
	unsigned long add;

	add = (unsigned long) p;
	print_strs("0x");
	print_long_hex(add);
	return (0);
}