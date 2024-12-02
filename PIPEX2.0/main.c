#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    t_pipex *pipex;
    pid_t   pid1;
    pid_t   pid2;

    if (argc != 5)
        error_exit(WRONG_ARGS_NUM);
    pipex = malloc(sizeof(t_pipex));
    if(!pipex)
        error_exit(MALLOC_ERROR);
    init_data(pipex, argv, env);
    if (pipe(pipex->pipe_end) == -1)
        error_exit(PIPE_ERROR);
    pid1 = fork_process(process_1, pipex);
    pid2 = fork_process(process_2, pipex);
    close(pipex->pipe_end[1]);
    close(pipex->pipe_end[0]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    clean_data(pipex);
    exit(EXIT_SUCCESS);
}