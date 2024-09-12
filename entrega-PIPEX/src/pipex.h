/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:32:23 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/12 09:38:15 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef EXIT_ARGUMENTS
#  define EXIT_ARGUMENTS 1
# endif
# ifndef EXIT_PIPE 
#  define EXIT_PIPE 2
# endif
# ifndef EXIT_FORK
#  define EXIT_FORK 3
# endif
# ifndef EXIT_FILE_OPEN
#  define EXIT_FILE_OPEN 4
# endif
# ifndef EXIT_EXECUTION
#  define EXIT_EXECUTION 5
# endif
# ifndef EXIT_COMMAND_NF
#  define EXIT_COMMAND_NF 127
# endif

void	free_arr(char *arr[]);
void	fork_process(pid_t *pid);
#endif
