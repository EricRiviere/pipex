/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:59:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/18 13:32:07 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hpointer(unsigned long ptr, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		print_hpointer(ptr / 16, counter);
	print_char(base[ptr % 16], counter);
}

void	print_pointer(unsigned long ptr, int *counter)
{
	if (!ptr)
	{
		print_string("(nil)", counter);
		return ;
	}
	else
	{
		print_string("0x", counter);
		print_hpointer(ptr, counter);
	}
}
