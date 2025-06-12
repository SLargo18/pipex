#include "../include/pipex.h"

void	create_pipe(t_pipex *data)
{
	if(pipe(data->pipefd) == -1)
		is_error("Pipe creation failed", 1, 0);
}