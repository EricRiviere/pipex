#include "pipex.h"

char    *get_path(char *comand, char **env)
{
    size_t  i;
    char    *partial_path;
    char    *path;
    char    **paths;

    i = 0;
    while (env[i] && !ft_strnstr(env[i], "PATH", 4))
        i++;
    path = env[i];
    paths = ft_split(path + 5, ':');
    i = 0;
    while (paths[i])
    {
        partial_path = ft_strjoin(paths[i], "/");
        path = ft_strjoin(partial_path, comand);
        free(partial_path);
        if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
        {
            free_arr(paths);
            return (path);
        }
        free(path);
        i++;
    }
    free_arr(paths);
    return (NULL);
}

void    execute_cmd(t_pipex *pipex, char **cmd, char *path)
{
    if (execve(path, cmd, pipex->env) == -1)
    {
        clean_data(pipex);
        error_exit(EXEC_ERROR);
    }
}

void    process_1(void *data)
{
    t_pipex *pipex;
    char    **av;

    pipex = (t_pipex *)data;
    av = pipex->argv;
    pipex->input_fd = open(av[1], O_RDONLY);
    if (pipex->input_fd == -1)
        error_exit(OPEN_ERROR);
    if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
        error_exit(DUP2_ERROR);
    if (dup2(pipex->pipe_end[1], STDOUT_FILENO) == -1)
        error_exit(DUP2_ERROR);
    close(pipex->pipe_end[1]);
    close(pipex->pipe_end[0]);
    execute_cmd(pipex, pipex->comand1, pipex->cmd1_path);
}

void    process_2(void *data)
{
    t_pipex *pipex;
    char    **av;

    pipex = (t_pipex *)data;
    av = pipex->argv;
    pipex->output_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (pipex->output_fd == -1)
        error_exit(OPEN_ERROR);
    if (dup2(pipex->pipe_end[0], STDIN_FILENO) == -1)
        error_exit(DUP2_ERROR);
    if (dup2(pipex->output_fd, STDOUT_FILENO) == -1)
        error_exit(DUP2_ERROR);
    close(pipex->pipe_end[0]);
    close(pipex->pipe_end[1]);
    execute_cmd(pipex, pipex->comand2, pipex->cmd2_path);
}

pid_t    fork_process(void (*foo)(void *), void *data)
{
    pid_t   fork_id;

    fork_id = fork();
    if (fork_id == -1)
        error_exit(FORK_ERROR);
    else if (fork_id == 0)
        foo(data);
    return (fork_id);
}