#include "../include/pipex.h"

void	create_pipe(t_pipex *data)
{
	if(pipe(data->pipefd) == -1)
		is_error("Pipe creation failed", 1, 0);
}

void	create_processes(t_pipex *data, char **argv, char **envp)
{
	open_file(data, argv);
	data->pid1 = fork();
	if (data->pid1 == -1)
		is_error("Fork failed", 1, 0);
	if (data->pid1 == 0)
		first_child(data, argv, envp);
	data->pid2 = fork();
}

void	child1(t_pipex *data, char **argv)
{
	close(data->pipefd[0]);
	if (data->infile == -1)
		is_error("Cannot open input file", 1, 0);
	if (dup2(data->infile, STDIN_FILENO) == -1
		|| (dup2(data->pipefd[1], STDIN_FILENO) == -1))
		is_error ("dup2 failed", 1, 0);
	close(data->infile);
	close(data->pipefd[1]);
}

void	first_child(t_pipex *data, char **argv, char **envp)
{
	child1(data, argv);
	execute_cmd(data->paths, data->cmd1, envp);
}
