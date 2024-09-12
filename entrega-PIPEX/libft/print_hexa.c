/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:05:43 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/18 13:00:59 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(unsigned int nb, char type, int *counter)
{
	char	*base;

	if (nb == 0)
	{
		print_char('0', counter);
		return ;
	}
	else
	{
		if (type == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		if (nb >= 16)
		{
			print_hexa(nb / 16, type, counter);
			print_hexa(nb % 16, type, counter);
		}
		else
			print_char(base[nb], counter);
	}
}
