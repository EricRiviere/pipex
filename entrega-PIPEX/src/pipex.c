/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:22:46 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/12 08:37:36 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*find_path(char *command, char *env[])
{
	int		i;
	char	**paths;
	char	*partial_path;
	char	*complete_path;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		partial_path = ft_strjoin(paths[i], "/");
		complete_path = ft_strjoin(partial_path, command);
		free(partial_path);
		if (access(complete_path, X_OK) == 0)
		{
			free_arr(paths);
			return (complete_path);
		}
		free(complete_path);
		i++;
	}
	free_arr(paths);
	return (0);
}

static void	exec_command(char *command, char *env[])
{
	char	**command_array;
	char	*path;
	char	*cmd_err;

	command_array = ft_split(command, ' ');
	cmd_err = ft_strjoin("zsh: command not found: ", command_array[0]);
	path = find_path(command_array[0], env);
	if (!path)
	{
		free_arr(command_array);
		ft_putstr_fd(cmd_err, 2);
		free(cmd_err);
		exit(EXIT_COMMAND_NF);
	}
	if (execve(path, command_array, env) == -1)
	{
		free_arr(command_array);
		free(path);
		perror("Execution error");
		exit(EXIT_EXECUTION);
	}
	free(command_array);
	free(path);
}

static void	read_process(char *argv[], int *pipe_fd, char *env[])
{
	int	input_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
	{
		perror("Problem opening file");
		exit(EXIT_FILE_OPEN);
	}
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
	exec_command(argv[2], env);
}

static void	write_process(char *argv[], int *pipe_fd, char *env[])
{
	int	output_fd;

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_fd == -1)
	{
		perror("Problem opening file");
		exit(EXIT_FILE_OPEN);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
	exec_command(argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_printf("Introduce 4 arguments:\n -IFile\n -Com_arr(x2)\n -OFile\n");
		exit(EXIT_ARGUMENTS);
	}
	if (pipe(pipe_fd) == -1)
	{
		(perror("Error creating pipe"));
		exit(EXIT_PIPE);
	}
	fork_process(&pid1);
	if (pid1 == 0)
		read_process(argv, pipe_fd, env);
	fork_process(&pid2);
	if (pid2 == 0)
		write_process(argv, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
