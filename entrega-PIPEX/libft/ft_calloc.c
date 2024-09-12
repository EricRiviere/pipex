/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:33:31 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/21 08:43:21 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	void	*dest;

	dest = malloc(number * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, number * size);
	return (dest);
}
