/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:04:30 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/25 08:41:43 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_check(char const *set, char const c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*new_str(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_check(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (s1[start] && char_check(set, s1[end - 1]))
		end--;
	trim = new_str(end - start);
	if (!trim)
		return (NULL);
	i = 0;
	while ((start + i) < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
