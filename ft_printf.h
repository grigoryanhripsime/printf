/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:45 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/01/29 19:20:21 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int print_charc(int c);
int print_strs(char *str);
int print_intd(int n);
int print_intu(unsigned int n);
int print_hexl(unsigned int n);
int print_hexu(unsigned int n);
int print_pointp(void *p);

#endif
