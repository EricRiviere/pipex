/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:37:14 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/21 09:08:56 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *f, size_t len)
{
	size_t	f_len;

	f_len = ft_strlen(f);
	if (f_len == 0)
		return ((char *)s);
	while (*s && len >= f_len)
	{
		if (ft_strncmp(s, f, f_len) == 0)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
