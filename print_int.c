/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:50:06 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/28 19:52:01 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int print_intd(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return(print_strs("-2147483648"));
		count += print_charc('-');
		n *= -1;
	}
	if (n > 9)
	{
		print_intd(n / 10);
		print_intd(n % 10);
	}
	else
		count += print_charc(n + '0');
	return (count);
}
