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
}
