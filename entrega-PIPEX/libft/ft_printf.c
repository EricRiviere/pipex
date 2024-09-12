/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:24:22 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/18 13:31:33 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list args, char type, int *counter)
{
	if (type == 'c')
		print_char(va_arg(args, int), counter);
	else if (type == 's')
		print_string(va_arg(args, char *), counter);
	else if (type == 'i' || type == 'd')
		print_di(va_arg(args, int), counter);
	else if (type == 'u')
		print_unsigned(va_arg(args, unsigned int), counter);
	else if (type == 'x' || type == 'X')
		print_hexa(va_arg(args, unsigned int), type, counter);
	else if (type == 'p')
		print_pointer(va_arg(args, unsigned long), counter);
	if (type == '%')
		print_char('%', counter);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				check_type(args, str[i], &counter);
		}
		else
			print_char(str[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
