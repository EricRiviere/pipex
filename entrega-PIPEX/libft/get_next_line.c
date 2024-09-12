/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:02:50 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/05 14:19:32 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*protect_join(char	*buffer, char *reading)
{
	char	*tmp;

	tmp = gnl_strjoin(buffer, reading);
	if (!tmp)
		return (ft_double_free(&buffer, NULL));
	return (tmp);
}

char	*read_line(int fd, char *buffer, int bytes)
{
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_double_free(&buffer, NULL));
	while (bytes > 0)
	{
		if (ft_strchr(tmp, '\n'))
			break ;
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_double_free(&buffer, &tmp));
		tmp[bytes] = '\0';
		buffer = protect_join(buffer, tmp);
		if (!buffer)
			return (NULL);
	}
	return (ft_double_free(&tmp, NULL), buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	char	*pos;
	int		end;
	int		start;

	if (!buffer)
		return (NULL);
	pos = ft_strchr(buffer, '\n');
	end = pos - buffer;
	if (!pos)
		end = ft_strlen(buffer);
	end++;
	line = ft_calloc(end + 1, sizeof(char));
	if (!line)
		return (NULL);
	start = -1;
	while (++start < end)
		line[start] = buffer[start];
	return (line);
}

char	*new_buffer(char *buffer)
{
	char	*new;
	int		new_start;
	int		size;
	int		i;
	char	*pos;

	pos = ft_strchr(buffer, '\n');
	new_start = pos - buffer;
	if (!pos)
		new_start = ft_strlen(buffer);
	if (!buffer[new_start])
		return (ft_double_free(&buffer, NULL));
	size = ft_strlen(buffer) - new_start;
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (ft_double_free(&buffer, NULL));
	i = 0;
	while (buffer[++new_start])
		new[i++] = buffer[new_start];
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd], 1);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line || !*line)
		return (ft_double_free(&buffer[fd], &line));
	buffer[fd] = new_buffer(buffer[fd]);
	return (line);
}
