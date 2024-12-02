#ifndef PIPEX_H
# define PIPEX_H

#include <sys/types.h> //--> For size_t & pid_t
#include <unistd.h> //--> For write & access(), fork(), dup2(), exeve()
#include <fcntl.h> //--> For open(open a file), O_RDONLY (open for read only), O_CREAT (create file if doesn't exist) O_TRUNC (to delete content if already exist)
#include <stdlib.h> // --> For exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <stdio.h> //--> stdin (standard input stream) stdout (standard output stream)
#include <sys/wait.h> //--> For waitpid (wait for a process to change status)
#include <stdlib.h> //--> For malloc (memory allocation)

typedef struct s_pipex
{
    char    **argv;
	char	**env;
	int		pipe_end[2];
	int		input_fd;
	int		output_fd;
	char	**comand1;
	char	**comand2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_pipex;

#define WRONG_ARGS_NUM "Wrong number of arguments recieved\n\n \
    Execution example:\n\n \
    './pipex infile comand_1 comand_2 outfile'\n"

#define ENV_NOT_FOUND "No env found\n"
#define COMMAND_NOT_FOUND "Command not found: "
#define PIPE_ERROR "Error creating pipe\n"
#define FORK_ERROR "Error forking process\n"
#define OPEN_ERROR "Error opening file\n"
#define DUP2_ERROR "Error duplicating fd\n"
#define EXEC_ERROR "Error executing comand\n"
#define MALLOC_ERROR "Error allocating memory\n"

//LIBFT
void    ft_putstr_fd(int fd, const char *str);
size_t  ft_strlen(const char *str);
char    *ft_substr(const char *str, unsigned int start, size_t len);
void    free_split(size_t i, char **arr);
size_t count_words(const char *str, char c);
char    **in_split(const char *str, char c, char **arr, size_t words_nbr);
char    **ft_split(const char *str, char c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *s, const char *f, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

//UTILS
void    error_exit(const char *error);
void    comand_error_exit(const char *error, char *comand);
void    free_arr(char **arr);
void    clean_data(t_pipex *pipex);
void    init_data(t_pipex *pipex, char **argv, char **env);

//FORK & EXECUTE
char    *get_path(char *comand, char **env);
void    execute_cmd(t_pipex *pipex, char **cmd, char *path);
void    process_1(void *data);
void    process_2(void *data);
pid_t    fork_process(void (*foo)(void *), void *data);

#endif