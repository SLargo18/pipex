#include "../include/pipex.h"

void	is_error(char *msg, int exit_code, int close_std)
{
	perror(msg);
	if (close_std)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
	}
	exit(exit_code);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_data(t_pipex *data)
{
	if (data->paths)
		free_array(data->paths);
	if (data->cmd1)
		free_array(data->cmd1);
	if (data->cmd2)
		free_array(data->cmd2);
}
