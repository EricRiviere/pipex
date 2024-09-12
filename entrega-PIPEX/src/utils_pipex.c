/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:58:49 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/12 08:36:49 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		(perror("Error forking process"));
		exit(EXIT_FORK);
	}
}

void	free_arr(char *arr[])
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
