/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:23:56 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/17 11:25:50 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str, int *counter)
{
	size_t	i;

	i = 0;
	if (!str)
		return (print_string("(null)", counter));
	while (str[i])
	{
		print_char(str[i], counter);
		i++;
	}
}
