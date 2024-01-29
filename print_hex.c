/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:34:19 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/29 17:49:59 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

//how many charecters will be in hex number
static int dec_hex_count(unsigned int n)
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

static char hex_charu(int n)
{
	if (n >= 10)
		return (n + 'A' - 10);
	return (n + '0');
}

int print_hexl(unsigned int n)
{
	int count;
	char* num;
	int i;

	i = 0;
	count = dec_hex_count(n);
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

int print_hexu(unsigned int n)
{
	int count;
	char* num;
	int i;

	i = 0;
	count = dec_hex_count(n);
	num = malloc((count + 1) * sizeof(char));
	if (!num)
		return (0);
	while (i < count)
	{
		num[count - i - 1] = hex_charu(n % 16);
		n /= 16;
		i++;
	}
	num[count - i - 1] = '\0';
	print_strs(num);
	free(num);
	return (count);
}