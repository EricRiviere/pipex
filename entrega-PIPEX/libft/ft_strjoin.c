/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:10:28 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/21 12:18:16 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, s1len + 1);
	ft_strlcat(s3, s2, s1len + s2len + 1);
	return (s3);
}
