#include "pipex.h"

void    error_exit(const char *error)
{
    ft_putstr_fd(2, error);
    exit(EXIT_FAILURE);
}

void    comand_error_exit(const char *error, char *comand)
{
    ft_putstr_fd(2, error);
    ft_putstr_fd(2, comand);
    ft_putstr_fd(2, "\n");
    exit(EXIT_FAILURE);
}

void    free_arr(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

void    clean_data(t_pipex *pipex)
{
    if (pipex->comand1)
        free_arr(pipex->comand1);
    if (pipex->comand2)
        free_arr(pipex->comand2);
    if (pipex->cmd1_path)
        free(pipex->cmd1_path);
    if (pipex->cmd2_path)
        free(pipex->cmd2_path);
}

void    init_data(t_pipex *pipex, char **argv, char **env)
{
    if (!env || !(*env))
        error_exit(ENV_NOT_FOUND);
    pipex->env = env;
    pipex->argv = argv;
    pipex->comand1 = ft_split(argv[2], ' ');
    pipex->comand2 = ft_split(argv[3], ' ');
    pipex->cmd1_path = get_path(pipex->comand1[0], env);
    pipex->cmd2_path = get_path(pipex->comand2[0], env);
    if (!pipex->cmd1_path)
        comand_error_exit(COMMAND_NOT_FOUND, pipex->comand1[0]);
    else if (!pipex->cmd2_path)
        comand_error_exit(COMMAND_NOT_FOUND, pipex->comand2[0]);
}