/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:31:24 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/17 13:25:48 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di(int nb, int *counter)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*counter) += 11;
		return ;
	}
	if (nb < 0)
	{
		print_char('-', counter);
		nb *= -1;
	}
	if (nb >= 10)
	{
		print_di(nb / 10, counter);
		print_di(nb % 10, counter);
	}
	else
		print_char(nb + 48, counter);
}

void	print_unsigned(unsigned int nb, int *counter)
{
	if (nb >= 10)
		print_unsigned(nb / 10, counter);
	print_char(nb % 10 + '0', counter);
}
