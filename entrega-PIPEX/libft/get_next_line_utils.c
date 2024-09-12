/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:06:53 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/05 14:19:45 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*new_str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	while (i < (num * size))
	{
		((char *)memory)[i] = '\0';
		i++;
	}
	return (memory);
}

char	*ft_double_free(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (NULL);
}
