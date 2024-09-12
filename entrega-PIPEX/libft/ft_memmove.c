/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:36:45 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/21 09:23:10 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dst;
	unsigned char	*sr;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (len == 0)
	{
		return (dst);
	}
	if (sr < dst && sr + len > dst)
	{
		ft_memmove(dst + 1, sr + 1, len - 1);
		*dst = *sr;
	}
	else
	{
		*dst = *sr;
		ft_memmove(dst + 1, sr + 1, len - 1);
	}
	return (dest);
}
/*
{
	unsigned char *d;
	const unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	if (d == s)
		return (dest);
	if (s < d && d < s + n)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return dest;
}
*/
